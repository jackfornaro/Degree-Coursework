#ifndef VECTOR3_H_
#define VECTOR3_H_

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for handling 3D vector
 */
class Vector3 {
	private:
		double x, y, z;
	public:
		/**
		 * @brief Default constructor to initializes vector.
		 * @return It returns an object of the vector class.
		 */
		Vector3();
		
		/**
		 * @brief Constructor to initializes server.
		 * @param corX the first argument
		 * @param corY the second argument
		 * @param corZ the third argument
		 * @return It returns an object of a 3D vector with the given values.
		 */
		Vector3(double corX, double corY, double corZ);
		
		/**
		 * @brief Copy constructor.
		 * @param v the first argument
		 * @return It returns an object of a 3D vector with the given values.
		 */
		Vector3(const Vector3 &v);
		
		/**
		 * @brief It prints out the coordinate of x, y, and z.
		 */
		void Print();
		
		/**
		 * @brief Add operator between two vectors
		 * @param v the first argument
		 * @return It updates the vector3 object with new value.
		 */
		Vector3 operator+(Vector3 v);
		
		/**
		 * @brief minus operator between two vectors
		 * @param v the first argument
		 * @return It updates the vector3 object with new value.
		 */
		Vector3 operator-(Vector3 v);
		
		/**
		 * @brief multiply operator between two vectors
		 * @param v the first argument
		 * @return It updates the vector3 object with new value.
		 */
		Vector3 operator*(double val);
		
		/**
		 * @brief divide operator between two vectors
		 * @param v the first argument
		 * @return It updates the vector3 object with new value.
		 */
		Vector3 operator/(double val);
		friend class CameraClass;
		friend class FindRobot;
		friend class ImageProcessor;
};

#endif // VECTOR3_H_
