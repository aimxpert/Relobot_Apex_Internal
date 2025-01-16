#pragma once
#include <algorithm>
#include <cmath>

namespace SDK
{
	namespace utils
	{
		namespace maths
		{
			class vector2
			{
			public:
				vector2()
				{
					x = y = 0.f;
				}

				vector2(float fx, float fy)
				{
					x = fx;
					y = fy;
				}

				float x, y;

			 

				inline vector2 operator-(const vector2& v) const {
					return vector2(x - v.x, y - v.y);
				}
			 
				inline vector2 operator+(const vector2& v) const {
					return vector2(x + v.x, y + v.y);
				}

				vector2 operator/(float input) const
				{
					return vector2{ x / input, y / input };
				}

				vector2 operator*(float input) const
				{
					return vector2{ x * input, y * input };
				}

				vector2& operator-=(const vector2& v)
				{
					x -= v.x;
					y -= v.y;
					return *this;
				}

				vector2& operator/=(float input)
				{
					x /= input;
					y /= input;
					return *this;
				}

				vector2& operator*=(float input)
				{
					x *= input;
					y *= input;
					return *this;
				}

				float length() const
				{
					return std::sqrt((x * x) + (y * y));
				}

				vector2 normalized() const
				{
					return { x / length(), y / length() };
				}

				float dot_product(vector2 input) const
				{
					return (x * input.x) + (y * input.y);
				}

				float distance(vector2 input) const
				{
					return (*this - input).length();
				}
				inline float Distance2(const vector2& Dst) {
					return sqrt(powf(this->x - Dst.x, 2) + powf(this->y - Dst.y, 2));
				}
				bool empty() const
				{
					return x == 0.f && y == 0.f;
				}
			};
			static float my_sqrt(float number)
			{
				long        i;
				float       x2, y;
				const float threehalfs = 1.5F;

				x2 = number * 0.5F;
				y = number;
				i = *(long*)&y; // floating point bit level hacking [sic]
				i = 0x5f3759df - (i >> 1); // Newton's approximation
				y = *(float*)&i;
				y = y * (threehalfs - (x2 * y * y)); // 1st iteration
				y = y * (threehalfs - (x2 * y * y)); // 2nd iteration

				return 1 / y;
			}

			class vector3
			{
			public:
				
				vector3() : x(0.f), y(0.f), z(0.f)
				{

				}
				bool is_nan() { return isnan(x) || isnan(x) || isnan(x); }

				vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
				{

				}
				~vector3()
				{

				}

				float x;
				float y;
				float z;
				static vector3 Zero() {
					return vector3(0, 0, 0);
				}
				inline float Dot(vector3 v)
				{
					return x * v.x + y * v.y + z * v.z;
				}
				bool empty() const
				{
					return x == 0.f && y == 0.f;
				}
				inline float Distance(vector3 v)
				{
					return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
				}
#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)

				float get_3d_dist(const vector3& Dst) {
					return my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(y - Dst.y) + powFFFFFFFFFFFFFFFFFFFFFF(z - Dst.z));
				}
				inline 	vector3& operator+=(const vector3& vector);
				vector3 operator+(vector3 v)
				{
					return vector3(x + v.x, y + v.y, z + v.z);
				}float dot(const vector3& vector)
				{
					return x * vector.x + y * vector.y + z * vector.z;
				}

				vector3 operator-(vector3 v)
				{
					return vector3(x - v.x, y - v.y, z - v.z);
				}
				inline float Length()
				{
					return sqrtf((x * x) + (y * y) + (z * z));
				}
				vector3 operator*(float input) const
				{
					return vector3{ x * input, y * input, z * input };
				}
				float length_2d() { return my_sqrt((x * x) + (z * z)); }
				vector3 multiply(const vector3& ref) const
				{
					return vector3(x * ref.x, y * ref.y, z * ref.z);
				}
				vector3 operator/(float input) const
				{
					return vector3{ x / input, y / input, z / input };
				}
				vector3 midPoint(vector3 v2) {
					return vector3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
				}
				vector3& operator-=(const vector3& v)
				{
					x -= v.x;
					y -= v.y;
					z -= v.z;

					return *this;
				}
				vector3& operator/=(float input)
				{
					x /= input;
					y /= input;
					z /= input;
					return *this;
				}
				vector3 operator-(const vector3& input) const
				{
					return vector3{ x - input.x, y - input.y, z - input.z };
				}
				float length_sqr() const
				{
					return (x * x) + (y * y) + (z * z);
				}
				float length() const
				{
					return std::sqrt(length_sqr());
				}
				float dot1(const vector3& vector)
				{
					return x * vector.x + y * vector.y + z * vector.z;
				}
				float length1()
				{
					return my_sqrt(dot1(*this));
				}
				float distance(vector3 input) const
				{
					return (*this - input).length();
				}
				void normalize_angle()
				{
					//while (x > 89.0f)
					//	x -= 180.f;

					//while (x < -89.0f)
					//	x += 180.f;




					while (x > 89.0f)
						x -= 180.0f;

					while (x < -89.0f)
						x += 180.0f;

					while (y > 180.0f)
						y -= 360.0f;

					while (y < -180.0f)
						y += 360.0f;
				}
				float Size()
				{
					return std::sqrt((x * x) + (y * y) + (z * z));
				}
				vector3 operator+(const vector3& v) const {
					return vector3(x + v.x, y + v.y, z + v.z);
				}

				vector3 clamp() {
					x = std::clamp(x, -89.0f, 89.0f);
					y = std::clamp(y, -180.0f, 180.0f);
					z = 0.0f;

					return *this;
				}
				vector3 normalize() {
					if (this->x > 180.0f)
						this->x -= 360.f;
					else if (this->x < -180.0f)
						this->x += 360.0f;

					if (this->y > 180.0f)
						this->y -= 360.0f;
					else if (this->y < -180.0f)
						this->y += 360.0f;

					this->z = 0.0f;
					return *this;
				}

				vector3 normalize231()
				{
					vector3 out = *this;
					auto l = length();
					if (l == 0)
						return *this;
					
					out.x /= l;
					out.y /= l;
					out.z /= l;
					return out;
				}
				vector3 Normalized11() {
					float len = Length();
					return vector3(x / len, y / len, z / len);
				}
#define M_PI_21 1.57079632679489661923

				static float my_cos(float x) { return my_sin(x + M_PI_21); }

				static float my_sin(float x)
				{
					// useful to pre-calculate
					double x2 = x * x;
					double x4 = x2 * x2;

					// Calculate the terms
					// As long as abs(x) < sqrt(6), which is 2.45, all terms will be positive.
					// Values outside this range should be reduced to [-pi/2, pi/2] anyway for
					// accuracy. Some care has to be given to the factorials. They can be
					// pre-calculated by the compiler, but the value for the higher ones will exceed
					// the storage capacity of int. so force the compiler to use unsigned long longs
					// (if available) or doubles.
					double t1 = x * (1.0 - x2 / (2 * 3));
					double x5 = x * x4;
					double t2 = x5 * (1.0 - x2 / (6 * 7)) / (1.0 * 2 * 3 * 4 * 5);
					double x9 = x5 * x4;
					double t3 = x9 * (1.0 - x2 / (10 * 11)) / (1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9);
					double x13 = x9 * x4;
					double t4 = x13 * (1.0 - x2 / (14 * 15)) /
						(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13);
					double x14 = x13 * x4;
					double t5 =
						x14 * (1.0 - x2 / (18 * 19)) /
						(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15 * 16 * 17);
					double x15 = x14 * x4;
					double t6 = x15 * (1.0 - x2 / (22 * 23)) /
						(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15 *
							16 * 17 * 18 * 19 * 20 * 21);
					// add some more if your accuracy requires them.
					// But remember that x is smaller than 2, and the factorial grows very fast
					// so I doubt that 2^17 / 17! will add anything.
					// Even t4 might already be too small to matter when compared with t1.

					// Sum backwards
					double result = t6;
					result += t5;
					result += t4;
					result += t3;
					result += t2;
					result += t1;

					return result;
				}

			};
			inline vector3& vector3::operator+=(const vector3& vector)
			{
				x += vector.x;
				y += vector.y;
				z += vector.z;

				return *this;
			}
			class vector4
			{
			public:
				float x;
				float y;
				float z;
				float w;

				vector4();
				vector4(float x, float y, float z, float w);

				vector4 operator+(const vector4& vector) const;
				vector4 operator-(const vector4& vector) const;
				vector4 operator-() const;
				vector4 operator*(float number) const;
				vector4 operator/(float number) const;

				vector4& operator+=(const vector4& vector);
				vector4& operator-=(const vector4& vector);
				vector4& operator*=(float number);
				vector4& operator/=(float number);

				bool operator==(const vector4& vector) const;
				bool operator!=(const vector4& vector) const;
				static vector4 Zero() { return { 0, 0, 0, 0 }; }

				inline float Dot(const vector4& vector)
				{
					return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
				}
				vector4 operator*(const vector4& v) const
				{
					return vector4(this->x * v.x,
						this->y * v.y,
						this->z * v.z,
						this->w * v.w);
				}
				inline float Distance(const vector4& vector)
				{
					return sqrt(
						(x - vector.x) * (x - vector.x) +
						(y - vector.y) * (y - vector.y) +
						(z - vector.z) * (z - vector.z) +
						(w - vector.w) * (w - vector.w));
				}
			};

			inline bool vector4::operator==(const vector4& vector) const
			{
				return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
			}

			inline bool vector4::operator!=(const vector4& vector) const
			{
				return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
			}

			inline vector4 vector4::operator+(const vector4& vector) const
			{
				return vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
			}

			inline vector4 vector4::operator-(const vector4& vector) const
			{
				return vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
			}

			inline vector4 vector4::operator-() const
			{
				return vector4(-x, -y, -z, -w);
			}

			inline vector4 vector4::operator*(float number) const
			{
				return vector4(x * number, y * number, z * number, w * number);
			}

			inline vector4 vector4::operator/(float number) const
			{
				return vector4(x / number, y / number, z / number, w / number);
			}

			class matrix
			{
			public:
				inline float* operator[](int i)
				{
					return m[i];
				}

				inline const float* operator[](int i) const
				{
					return m[i];
				}

				inline float* Base()
				{
					return &m[0][0];
				}

				inline const float* Base() const
				{
					return &m[0][0];
				}
			public:

				inline matrix()
				{
				}

				inline matrix(
					float m00, float m01, float m02, float m03,
					float m10, float m11, float m12, float m13,
					float m20, float m21, float m22, float m23,
					float m30, float m31, float m32, float m33)
				{
					Init(
						m00, m01, m02, m03,
						m10, m11, m12, m13,
						m20, m21, m22, m23,
						m30, m31, m32, m33
					);
				}

				inline void Init(
					float m00, float m01, float m02, float m03,
					float m10, float m11, float m12, float m13,
					float m20, float m21, float m22, float m23,
					float m30, float m31, float m32, float m33
				)
				{
					m[0][0] = m00;
					m[0][1] = m01;
					m[0][2] = m02;
					m[0][3] = m03;

					m[1][0] = m10;
					m[1][1] = m11;
					m[1][2] = m12;
					m[1][3] = m13;

					m[2][0] = m20;
					m[2][1] = m21;
					m[2][2] = m22;
					m[2][3] = m23;

					m[3][0] = m30;
					m[3][1] = m31;
					m[3][2] = m32;
					m[3][3] = m33;
				}

				matrix transpose() const
				{
					return matrix(
						m[0][0], m[1][0], m[2][0], m[3][0],
						m[0][1], m[1][1], m[2][1], m[3][1],
						m[0][2], m[1][2], m[2][2], m[3][2],
						m[0][3], m[1][3], m[2][3], m[3][3]);
				}

				float m[4][4];
			};

			using vec2_t = vector2;
			using vec3_t = vector3;
			using Vector3 = vector3;
			using vec4_t = vector4;
			using mat4x4_t = matrix;

			struct TransformAccessReadOnly
			{
				uintptr_t pTransformData;
			};

			struct TransformData
			{
				uintptr_t pTransformArray;
				uintptr_t pTransformIndices;
			};

			struct Matrix34
			{
				vector4 vec0;
				vector4 vec1;
				vector4 vec2;
			};
			class VMatrix
			{
			public:
				VMatrix()
					: m{ { 0, 0, 0, 0 },
						 { 0, 0, 0, 0 },
						 { 0, 0, 0, 0 },
						 { 0, 0, 0, 0 } }
				{}

				VMatrix(const VMatrix&) = default;

				VMatrix transpose() {
					VMatrix m;

					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							m.m[i][j] = this->m[j][i];

					return m;
				}

				void matrix_identity() {
					memset(this, 0, sizeof(VMatrix));
					m[0][0] = 1.0f;
					m[1][1] = 1.0f;
					m[2][2] = 1.0f;
					m[3][3] = 1.0f;
				}

				bool empty() {
					if (!m[3][0] && !m[3][1] && !m[3][2] && !m[2][1] && !m[2][0] && !m[2][2])
						return true;

					return false;
				}
				Vector3 MultiplyPoint3x4(Vector3 point)
				{
					Vector3 result;
					result.x = m[0][0] * point.x + m[0][1] * point.y + m[0][2] * point.z + m[0][3];
					result.y = m[1][0] * point.x + m[1][1] * point.y + m[1][2] * point.z + m[1][3];
					result.z = m[2][0] * point.x + m[2][1] * point.y + m[2][2] * point.z + m[2][3];
					return result;
				}
				Vector3 operator*(const Vector3& vec) {
					VMatrix m;

					m[3][0] = vec.x;
					m[3][1] = vec.y;
					m[3][2] = vec.z;

					m[0][0] = 1;
					m[1][1] = 1;
					m[2][2] = 1;


					m[0][3] = 0.0f;
					m[1][3] = 0.0f;
					m[2][3] = 0.0f;
					m[3][3] = 1.0f;

					auto result = m * (*this);

					return Vector3{ result[3][0], result[3][1], result[3][2] };
				}

				VMatrix operator*(const VMatrix& _m2) {
					auto _m = *this;

					VMatrix out;
					out[0][0] = _m[0][0] * _m2[0][0] + _m[0][1] * _m2[1][0] + _m[0][2] * _m2[2][0] + _m[0][3] * _m2[3][0];
					out[0][1] = _m[0][0] * _m2[0][1] + _m[0][1] * _m2[1][1] + _m[0][2] * _m2[2][1] + _m[0][3] * _m2[3][1];
					out[0][2] = _m[0][0] * _m2[0][2] + _m[0][1] * _m2[1][2] + _m[0][2] * _m2[2][2] + _m[0][3] * _m2[3][2];
					out[0][3] = _m[0][0] * _m2[0][3] + _m[0][1] * _m2[1][3] + _m[0][2] * _m2[2][3] + _m[0][3] * _m2[3][3];
					out[1][0] = _m[1][0] * _m2[0][0] + _m[1][1] * _m2[1][0] + _m[1][2] * _m2[2][0] + _m[1][3] * _m2[3][0];
					out[1][1] = _m[1][0] * _m2[0][1] + _m[1][1] * _m2[1][1] + _m[1][2] * _m2[2][1] + _m[1][3] * _m2[3][1];
					out[1][2] = _m[1][0] * _m2[0][2] + _m[1][1] * _m2[1][2] + _m[1][2] * _m2[2][2] + _m[1][3] * _m2[3][2];
					out[1][3] = _m[1][0] * _m2[0][3] + _m[1][1] * _m2[1][3] + _m[1][2] * _m2[2][3] + _m[1][3] * _m2[3][3];
					out[2][0] = _m[2][0] * _m2[0][0] + _m[2][1] * _m2[1][0] + _m[2][2] * _m2[2][0] + _m[2][3] * _m2[3][0];
					out[2][1] = _m[2][0] * _m2[0][1] + _m[2][1] * _m2[1][1] + _m[2][2] * _m2[2][1] + _m[2][3] * _m2[3][1];
					out[2][2] = _m[2][0] * _m2[0][2] + _m[2][1] * _m2[1][2] + _m[2][2] * _m2[2][2] + _m[2][3] * _m2[3][2];
					out[2][3] = _m[2][0] * _m2[0][3] + _m[2][1] * _m2[1][3] + _m[2][2] * _m2[2][3] + _m[2][3] * _m2[3][3];
					out[3][0] = _m[3][0] * _m2[0][0] + _m[3][1] * _m2[1][0] + _m[3][2] * _m2[2][0] + _m[3][3] * _m2[3][0];
					out[3][1] = _m[3][0] * _m2[0][1] + _m[3][1] * _m2[1][1] + _m[3][2] * _m2[2][1] + _m[3][3] * _m2[3][1];
					out[3][2] = _m[3][0] * _m2[0][2] + _m[3][1] * _m2[1][2] + _m[3][2] * _m2[2][2] + _m[3][3] * _m2[3][2];
					out[3][3] = _m[3][0] * _m2[0][3] + _m[3][1] * _m2[1][3] + _m[3][2] * _m2[2][3] + _m[3][3] * _m2[3][3];

					return out;
				}

				float* operator[](size_t i) { return m[i]; }
				const float* operator[](size_t i) const { return m[i]; }

				union {
					struct {
						float _11, _12, _13, _14;
						float _21, _22, _23, _24;
						float _31, _32, _33, _34;
						float _41, _42, _43, _44;
					};
					float m[4][4];
				};
			};

		}
	}
}
