# Git Cheat Sheet

1. **Config**
  - This tool allows you to get and set configuration variables that control how Git looks and operates.
  - These variables can go to three different places depending on the ty0pe of variable.
  
2. **Clone**
  - This tool is used to make a copy of an existing repository in a new directory.
  - It always copies an exisiting Git respository.
  
3. **Remote**
  - A remote repository is a version of your project that is hosted in a different location than where it was created.
  - This command makes it relatively easy to share your work when collaborating with others.

4. **Status**
  - This command displays the differences in paths of the the index file and the head commit, and differences in the paths of the working tree and index file.
  - When using the first example, run '<git commit>' to commit, while in the second example you must run '<git add>' before running '<git commit>'.
  
5. **Commit**
  - A commit contains the contents of an index file and gives a message to describe the changes.
  - It is a direct child of the head and the branch is updated to point to it.
  
6. **Push**
  - The main purpose is to update the remote references using local ones, and sending indexed items to the given reference point.
  - If the configuration is missing in the current branch, it will default to the origin of the branch.
  
7. **Pull**
  - Incorporates the changes from a remote repository into the current branch.
  - '<git pull>' runs '<git fetch>' which then calls '<git mege>' which merges the branch heads into the current branch.
  
8. **Add**
  - This tool prepares the content from the current working tree for the next commit.
  - Adds all of the content of the existing paths, but can be edited so only some of the changes are applied.
