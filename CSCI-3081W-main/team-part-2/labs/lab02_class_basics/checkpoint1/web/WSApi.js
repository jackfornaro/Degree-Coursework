function WSApi() {
    var self = this;
    this.socket = new WebSocket("ws://" + location.hostname+(location.port ? ':'+location.port: ''), "web_server");
    this.callbacks = {};
    this.requestId = 0;

    this.onmessage = null;

    this.socket.onmessage = function (msg) {
        var data = JSON.parse(msg.data);
        if ("id" in data) {
            self.callbacks[data.id](data);
        }
        if (self.onmessage) {
            self.onmessage(msg, data);
        }
    }

    this.connect = new Promise(function(resolve, reject) {
        self.socket.onopen = function() {
            resolve(self.socket);
        };
        self.socket.onerror = function(err) {
            console.log(err);
            reject(err);
        }
        self.socket.onclose = function (event) {
            console.log(event);
        }
    });

    this.connected = false;

    this.connect.then(function() {
        self.connected = true;
    });
}

WSApi.prototype.sendCommand = function(cmd, data, calcVal) {
    let self = this;

    if (self.connected) {
        data.command = cmd;
        data.id = this.requestId;
        this.socket.send(JSON.stringify(data));
        let promise = new Promise(function(resolve, reject) {
            self.callbacks[self.requestId] = function(data) {
                if (calcVal) {
                    resolve(calcVal(data)); 
                }
                else {
                    resolve(data);
                }
                delete self.callbacks[data.id];
            }
        });
        this.requestId++;
        return promise;
    }
    else {
        return new Promise(function(resolve, reject) {
            self.connect.then(function() {
                self.connected = true;
                    self.sendCommand(cmd, data, calcVal).then(
                        function(data) {
                            resolve(data);
                        });
                }
            );
        });
    }

}