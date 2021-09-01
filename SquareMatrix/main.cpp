#include "SquareMatrix.h"
#include <iostream>
#include <future>
#include <iostream>
#include <vector>

template <typename T>
void ReadOut(SquareMatrix<T> & x) {
    auto size = x.size();
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cout << x.at(i,j);
        }
        std::cout << std::endl;
    }
}

template <typename T>
void SetMatrix(SquareMatrix<T> &m, int size, T value) {
    m.resize(size);
    for (int i{0}; i < size; i++)
        for (int j{0}; j < size; j++)
            m.at(i, j) = value;
}

template <typename T>
bool MatricesEqual(SquareMatrix<T> & x, SquareMatrix<T> & y) {
    if( !(x.size() == y.size()) ) {
        return false;
    }
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < x.size(); ++j) {
            if (x.at(i,j) != y.at(i,j)) {
                return false;
            }
        }
    }
    return true;
}
//void Test1()
//{
//    SquareMatrix<short> mat;
//
//    if (mat.size() != 0)
//    {
//        cout << "ERROR: Either the default constructor or size() are faulty\n";
//        cout << "Test1 is stoped\n";
//        return;
//    }
//
//    mat.resize(4);
//    if (mat.size() != 4)
//    {
//        cout << "ERROR: Either a resize() or size() are faulty\n";
//        cout << "Test1 is stoped\n";
//        return;
//    }
//
//    mat.at(3, 3) = 456;
//    if (mat.at(3, 3) != 456)
//    {
//        cout << "ERROR: at() is faulty\n";
//        cout << "Test1 is stoped\n";
//        return;
//    }
//
//    mat.resize(5);
//
//    cout << "test 1 is passed\n";
//}
//
//template<typename T>
//void SetMatrix(SquareMatrix<T>& m, int size, T value)
//{
//    m.resize(size);
//    for (int i{ 0 }; i < size; i++)
//        for (int j{ 0 }; j < size; j++)
//            m.at(i, j) = value;
//}
//
//void Test2()
//{
//    SquareMatrix<int> m1;
//    SetMatrix<int>(m1, 6, 8);
//
//    SquareMatrix<int> m2;
//    SetMatrix<int>(m2, 6, 8);
//
//    if(not (m1==m2))
//    {
//        cout << "ERROR: operator== is faulty\n";
//        cout << "Test2 is stoped\n";
//        return;
//    }
//
//    SetMatrix<int>(m2, 5, 8);
//    if (m1 == m2)
//    {
//        cout << "ERROR: operator== is faulty\n";
//        cout << "Test2 is stoped\n";
//        return;
//    }
//
//    SetMatrix<int>(m2, 7, 8);
//    if (m1 == m2)
//    {
//        cout << "ERROR: operator== is faulty\n";
//        cout << "Test2 is stoped\n";
//        return;
//    }
//
//    SetMatrix<int>(m2, 6, 6);
//    if (m1 == m2)
//    {
//        cout << "ERROR: operator== is faulty\n";
//        cout << "Test2 is stoped\n";
//        return;
//    }
//
//    cout << "test 2 is passed\n";
//}
//
//void Test3()
//{
//    SquareMatrix<double> m1;
//    SetMatrix<double>(m1, 5, 4.0);
//
//    SquareMatrix<double> m2{ m1 };
//
//    if(not (m1==m2))
//    {
//        cout << "ERROR: copy constructor is faulty\n";
//        cout << "Test3 is stoped\n";
//        return;
//    }
//
//    SquareMatrix<double> m3{ move(m1) };
//
//    if (not (m3 == m2))
//    {
//        cout << "ERROR: move constructor is faulty\n";
//        cout << "Test3 is stoped\n";
//        return;
//    }
//
//    cout << "test 3 is passed\n";
//}
//
//void Test4()
//{
//    SquareMatrix<double> m1;
//    SetMatrix<double>(m1, 5, 4.0);
//
//    SquareMatrix<double> m2;
//
//    m2 = m1;
//    if(not (m2==m1))
//    {
//        cout << "ERROR: copy assignment is faulty\n";
//        cout << "Test4 is stoped\n";
//        return;
//    }
//
//    SquareMatrix<double> m3;
//    SetMatrix<double>(m3, 10, 20);
//
//    m3 = m2;
//    if (not (m3 == m2))
//    {
//        cout << "ERROR: copy assignment is faulty\n";
//        cout << "Test4 is stoped\n";
//        return;
//    }
//
//    SquareMatrix<double> empty_mat;
//    m3 = empty_mat;
//
//    SquareMatrix<double> m4;
//
//    m4 = move(m1);
//
//    SquareMatrix<double> m5;
//    SetMatrix<double>(m5, 9, 19);
//
//    m5 = move(m2);
//    if (not (m4 == m5))
//    {
//        cout << "ERROR: move assignment is faulty\n";
//        cout << "Test4 is stoped\n";
//        return;
//    }
//
//    m5 = empty_mat;
//
//    SquareMatrix<double> m6;
//    SetMatrix<double>(m6, 5, 4.0);
//    m6 = m6;
//    if (m6.at(4,4)!=4.0)
//    {
//        cout << "ERROR: copy assignment (self-assignment obj1=obj1) is faulty\n";
//        cout << "Test4 is stoped\n";
//        return;
//    }
//
//    SquareMatrix<double> m7;
//    SetMatrix<double>(m7, 5, 7.0);
//    m7 = move(m7);
//    if (m7.at(4, 4) != 7.0)
//    {
//        cout << "ERROR: move assignment (self-assignment obj1=move(obj1) ) is faulty\n";
//        cout << "Test4 is stoped\n";
//        return;
//    }
//
//    SquareMatrix<double> m8, m9, m10;
//    SetMatrix<double>(m10, 7, 12.0);
//    m8 = m9 = m10;
//
//    if (not (m8 == m9))
//    {
//        cout << "ERROR: copy assignment is faulty\n";
//        cout << "Test4 is stoped\n";
//        return;
//    }
//
//    SetMatrix<double>(m10, 7, 3.0);
//    m8 = m9 = move(m10);
//
//    if (not (m8 == m9))
//    {
//        cout << "ERROR: move assignment is faulty\n";
//        cout << "Test4 is stoped\n";
//        return;
//    }
//
//    cout << "test 4 is passed\n";
//}
//
//void Test5()
//{
//    SquareMatrix<int> m1;
//    SetMatrix<int>(m1, 5, 3);
//
//    SquareMatrix<int> m2;
//    SetMatrix<int>(m2, 5, 4);
//
//    SquareMatrix<int> m3;
//    m3 = m1 + m2;
//
//    bool ok{ true };
//    if (m3.size() != 5)
//        ok = false;
//    for (int i{ 0 }; i < 5; i++)
//        for (int j{ 0 }; j < 5; j++)
//            if (m3.at(i, j) != 7)
//                ok = false;
//
//    if(ok==false)
//    {
//        cout << "ERROR: operator+ is faulty\n";
//        cout << "Test5 is stoped\n";
//        return;
//    }
//
//    cout << "test 5 is passed\n";
//}
//
//int main()
//{
//    Test1();
//    Test2();
//    Test3();
//    Test4();
//    Test5();
//
//    return 0;
//}


//#include <iostream>
//#include "SquareMatrix.h"
//using namespace std;
//
//
//int main() {
//
//    SquareMatrix <int> SquareMatrix1;
//
//    SquareMatrix1.resize(2);
//    SquareMatrix <int> SquareMatrix2;
////    SquareMatrix <int> SquareMatrix3;
////    SquareMatrix <int> SquareMatrix4;
////    SquareMatrix1.resize(4);
//    SquareMatrix2.resize(2);
////    SquareMatrix3.resize(3);
////    SquareMatrix4.resize(2);
//
//    SquareMatrix1.at(0,1)= 6;
//    SquareMatrix1.at(1,1)= 3;
//    SquareMatrix1.at(1,0)= 2;
//    SquareMatrix1.at(0,0)= 5;
//
//
//    SquareMatrix2.at(0,1)= 1;
//    SquareMatrix2.at(1,1)= 2;
//    SquareMatrix2.at(1,0)= 1;
//    SquareMatrix2.at(0,0)= 1;
//
////    SquareMatrix <int> SquareMatrix0 = move(SquareMatrix2); //call move assignment
////    SquareMatrix <int> SquareMatrix0 (move(SquareMatrix2)); //call move conctructor
////    SquareMatrix <int> SquareMatrix000 = SquareMatrix2;
//    SquareMatrix <int> SquareMatrix0;
//    SquareMatrix0 = SquareMatrix1 = SquareMatrix2; //call copy assignment;
//
//
//
//    cout << SquareMatrix0.at(0,0) <<  " " << SquareMatrix0.at(0,1) << endl;
//    cout << SquareMatrix0.at(1,0) <<  " " << SquareMatrix0.at(1,1) << endl;
//
////    SquareMatrix3.at(0,1)= 4;
////    SquareMatrix3.at(1,1)= 4;
////    SquareMatrix3.at(1,0)= 4;
////    SquareMatrix3.at(0,0)= 4;
////
////    SquareMatrix4.at(0,1)= 1;
////    SquareMatrix4.at(1,1)= 1;
////    SquareMatrix4.at(1,0)= 1;
////    SquareMatrix4.at(0,0)= 1;
//
//
////    SquareMatrix1.~SquareMatrix(); //call destructor, no need to call it is called at the end of main function
////    SquareMatrix <int> cc = SquareMatrix1; //call copy conctructor
//
////    SquareMatrix1 = SquareMatrix2 = SquareMatrix3; //call copy assignment;
////    SquareMatrix1 = SquareMatrix1.operator+(SquareMatrix2); //call operator +
//
//
//// test operator ==
////    cout << "SquareMatrix2 and SquareMatrix4 size = 2;   content equal"
////    if (SquareMatrix2.operator==(SquareMatrix4))
////    {
////        cout << "test operator== : SquareMatrix2 == SquareMatrix4" << endl;
////    } else
////    {
////        cout << "test operator== : SquareMatrix2 != SquareMatrix4" << endl;
////    }
//
//
////    How to test move assignment ???
////    SquareMatrix <int> SquareMatrix5;
////    SquareMatrix <int> SquareMatrix4;
////    SquareMatrix5 = move(SquareMatrix4);
//
//
////    SquareMatrix SquareMatrix2(4);
////    cout << SquareMatrix1.at(0,0) <<  endl;
////    cout << SquareMatrix1.at(1,1) << endl;
//
//
////    cout << cc.at(2,2) << endl;
////    cout << SquareMatrix1 << endl;
////    SquareMatrix SquareMatrix1 = SquareMatrix2;
////    cout << SquareMatrix1 <<endl;
//    return 0;
//}
