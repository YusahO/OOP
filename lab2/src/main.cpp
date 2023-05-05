#include <iostream>
#include "BinarySearchTree.hpp"

// using namespace MyMatrix;

int main()
{
    // std::cout << "=== CONSTRUCTORS ===" << std::endl;
    // {
    //     size_t q = 2, w = 3;
    //     std::cout << "Constructor with two numbers:\n";
    //     BinarySearchTree<int> a(q, w);
    //     std::cout << a << std::endl;
    //     std::cout << "Constructor with filler \tMatrix<float> b(2, 3, 26):\n";
    //     Matrix<float> b(q, w, 26);
    //     std::cout << b << std::endl;
    //     std::cout << "Constructor with initialization list \tMatrix<float> c({ { 1., 2. }, { -3., -4. } }):\n";
    //     Matrix<float> c({{1.,  2.},
    //                      {-3., -4.}});
    //     std::cout << c << std::endl;
    //     std::cout << "Constructor with copy \tMatrix<float> d(c):\n";
    //     const Matrix<float>& d(c);
    //     std::cout << d << std::endl;
    //     std::cout << "Constructor for C matrix \tint c_matr[][3] = {{1, 2, 3}, {4, 5, 6}}:\n";
    //     int c_matr[][3] = {{1, 2, 3}, {4, 5, 6}};
    //     Matrix<int> cpp_matr(2, 3, reinterpret_cast<const int *>(c_matr));
    //     std::cout << cpp_matr << std::endl;
    //     std::cout << "Constructor with iterator \tMatrix<int> ee(2, 2, e.begin()):\n";
    //     Matrix<int> e = {{1, 2, 3}, {4, 5, 6}};
    //     Matrix<int> ee(2, 2, e.begin());
    //     std::cout << ee << std::endl;
    //     std::cout << "Constructor from float to int \tMatrix<int> f(c):\n";
    //     Matrix<int> f(c);
    //     std::cout << f << std::endl;

    //     //Создание матрицы из массива
    //     std::cout << "Constructor with vectors \tv { {1, 2}, {3, 4}, {5, 6} } g(v):\n";
    //     std::vector<std::vector<int>> v { {1, 2}, {3, 4}, {5, 6} };
    //     Matrix<int> g(v);
    //     std::cout << g << std::endl;

    //     std::cout << std::endl << std::endl;

    // }

    // std::cout << "=== GET/SET ELEMENTS ===" << std::endl;
    // {
    //     Matrix<int> a = {{-0, -1, -2}, {-10, -11, -12}};
    //     std::cout << "INIT A\n" << a;
    //     std::cout << "Get element by id by [1][1] and .at(1, 2)\n";
    //     std::cout << a[1][1] << "\t" << a.at(1, 2) << std::endl;
    //     std::cout << "Set element by id by [1][1] = 0 and .at(1, 2) and .set(1, 2, 0) = 0\n";
    //     a[1][1] = 999;
    //     a.at(1, 2) = 999999;
    //     a.set(1, 2, 999999);
    //     std::cout << a[1][1] << "\t" << a.at(1, 2)<< std::endl;

    // }

    // std::cout << "=== MATH with matrix ===" << std::endl;
    // {
    //     Matrix<float> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //     Matrix<float> b({{7, 4, 2}, {1, -5, -6}, {1, 0, 1}});
    //     Matrix<float> buf;
    //     std::cout << "INIT A\n" << a << std::endl;
    //     std::cout << "INIT B\n" << b << std::endl;
    //     std::cout << "--- MATH BETWEEN MATRIX (operations) ---" << std::endl;
    //     buf = a + b;
    //     std::cout << "A + B\n" << buf << std::endl;
    //     buf = a - b;
    //     std::cout << "A - B\n" << buf << std::endl;
    //     buf = a * b;
    //     std::cout << "A * B\n" << buf << std::endl;
    //     buf = a / b;
    //     std::cout << "A / B\n" << buf << std::endl;
    //     std::cout << "\n";

    //     std::cout << "--- MATH BETWEEN MATRIX (methods) ---" << std::endl;
    //     buf = a.addMatrix(b);
    //     std::cout << "A + B\n" << buf << std::endl;
    //     buf = a.subMatrix(b);
    //     std::cout << "A - B\n" << buf << std::endl;
    //     buf = a.mulMatrix(b);
    //     std::cout << "A * B\n" << buf << std::endl;
    //     buf = a.divMatrix(b);
    //     std::cout << "A / B\n" << buf << std::endl;
    //     std::cout << std::endl << std::endl;
    // }

    // std::cout << "=== MATH WITH NUM ===" << std::endl;
    // {
    //     Matrix<float> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //     float b = -10.5;
    //     Matrix<float> buf;
    //     std::cout << "INIT A\n" << a << std::endl;
    //     std::cout << "INIT B\n" << b << std::endl << std::endl;
    //     std::cout << "--- MATH WIH NUMBER (operations) ---" << std::endl;
    //     buf = a + b;
    //     std::cout << "A + B\n" << buf << std::endl;
    //     buf = a - b;
    //     std::cout << "A - B\n" << buf << std::endl;
    //     buf = a * b;
    //     std::cout << "A * B\n" << buf << std::endl;
    //     buf = a / b;
    //     std::cout << "A / B\n" << buf << std::endl;
    //     std::cout << "\n";

    //     std::cout << "--- MATH WITH NUMBER (methods) ---" << std::endl;
    //     buf = a.addEntity(b);
    //     std::cout << "A + B\n" << buf << std::endl;
    //     buf = a.subEntity(b);
    //     std::cout << "A - B\n" << buf << std::endl;
    //     buf = a.mulEntity(b);
    //     std::cout << "A * B\n" << buf << std::endl;
    //     buf = a.divEntity(b);
    //     std::cout << "A / B\n" << buf << std::endl;
    //     std::cout << std::endl << std::endl;
    //     a.addEntity(5);
    // }

    // std::cout << "=== MATH WITH COPY ===" << std::endl;
    // {
    //     Matrix<float> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //     Matrix<float> b({{7, 4, 2}, {1, -5, -6}, {1, 0, 1}});
    //     float buf = -100;
    //     std::cout << "INIT A\n" << a << std::endl;
    //     std::cout << "INIT B\n" << b << std::endl;
    //     std::cout << "--- MATH BETWEEN MATRIX ---" << std::endl;
    //     a.addToMatrix(b);
    //     std::cout << "A += B\n" << a << std::endl;
    //     a.subToMatrix(b);
    //     std::cout << "A -= B\n" << a << std::endl;
    //     a.mulToMatrix(b);
    //     std::cout << "A *= B\n" << a << std::endl;
    //     a.divToMatrix(b);
    //     std::cout << "A /= B\n" << a << std::endl;
    //     std::cout << "\n";

    //     std::cout << "--- MATH WITH NUMBER (methods) ---" << std::endl;
    //     std::cout << "INIT BUF\n" << buf << std::endl;
    //     a.addToEntity(buf);
    //     std::cout << "A += buf\n" << a << std::endl;
    //     a.subToEntity(buf);
    //     std::cout << "A -= buf\n" << a << std::endl;
    //     a.mulToEntity(buf);
    //     std::cout << "A *= buf\n" << a << std::endl;
    //     a.divToEntity(buf);
    //     std::cout << "A /= buf\n" << a << std::endl;
    //     std::cout << std::endl << std::endl;
    // }

    // std::cout << "=== MATRIX OPERATIONS ===" << std::endl;
    // {
    //     Matrix<int> a = {{1, 2, 3,}, {4, 5, 6}};
    //     Matrix<int> buffer;
    //     std::cout << "INIT A\n" << a << std::endl;
    //     buffer = a.transpose();
    //     std::cout << "Transpose A\n" << buffer << std::endl;
    //     buffer = a.negative();
    //     std::cout << "Negative A\n" << buffer << std::endl;
    //     Matrix<int> b = {{1, 2}, {4, 5}};
    //     buffer = b.inverse();
    //     std::cout << "Inverse B {1, 2}, {3, 4}\n" << buffer << std::endl;
    //     std::cout << std::endl << std::endl;
    // }
    std::cout << "=== TREE OPERATIONS ===" << std::endl;
    {
        std::cout << "--- INSERTION ---" << std::endl;
        BinarySearchTree<int> tree;
        int arr[] = { 5, 3, 7, 2, 4, 6, 8, 1, 9};
        for (size_t i = 0; i < sizeof(arr) / sizeof(int); ++i)
        {
            tree.Insert(arr[i]);
        }
        std::cout << "tree: " << tree << std::endl;
        std::cout << "--- FIND ---" << std::endl;
        for (size_t i = 0; i < sizeof(arr) / sizeof(int); ++i)
        {
            std::cout << *tree.Find(arr[i]) << " ";
        }
        std::cout << std::endl;
        std::cout << "--- REMOVE ---" << std::endl;
        {
            auto beg_del = ++tree.begin();
            auto end_del = --tree.end();
            std::cout << "before del [" << *beg_del << ", " << *end_del << "):\n" << tree << std::endl;
            tree.Erase(beg_del, end_del);
            std::cout << "after: " << tree << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "=== ITERATORS ===" << std::endl;
    {
        std::cout << "--- ITERATORS not const tree ---" << std::endl;
        BinarySearchTree<int> a({ 1, 5, 2, 3, 4, 0, 6, 8, 7 });
        std::cout << "INIT A\n" << a << std::endl;

        std::cout << "For each const auto &elem with separate ' '\n";
        for (const auto &elem : a)
            std::cout << elem << " ";
        std::cout << std::endl;
        std::cout << "For each reverse auto &elem with separate ' '\n";
        for (auto rit = a.rbegin(); rit != a.rend(); ++rit)
            std::cout << *rit << " ";
        std::cout << "\nFor each const reverse auto &elem with separate ' '\n";
        const BinarySearchTree<int> &ca = a;
        for (auto rit = ca.rbegin(); rit != ca.rend(); ++rit)
            std::cout << *rit << " ";
        std::cout << std::endl;

        std::cout << "--- ITERATORS const tree ---" << std::endl;
        const BinarySearchTree<float> const_c{1, 5, 2, 3, 4, 0, 6, 8, 7};
        std::cout << "For each const auto &elem with separate ' '\n";
        for (const auto &elem : const_c)
            std::cout << elem << " ";
        std::cout << std::endl;
        std::cout << "For each const reverse auto &elem with separate ' '\n";
        for (auto it = const_c.rbegin(); it != const_c.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    // std::cout << "=== RESIZE ===" << std::endl;
    // {
    //     Matrix<float> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //     std::cout << "INIT A\n" << a << std::endl;
    //     std::cout << "SIZE OF A\n" << a.size() << std::endl << std::endl;
    //     std::cout << "INSERT ROW AT \t1 with fill 0\n";
    //     a.insertRow(1, 0);
    //     std::cout << a << std::endl;
    //     std::cout << "INSERT COL AT \t1 with fill 0\n";
    //     a.insertCol(1, 0);
    //     std::cout << a << std::endl;
    //     std::cout << "DELETE ROW AT \t1\n";
    //     a.deleteRow(1);
    //     std::cout << a << std::endl;
    //     std::cout << "DELETE COL AT \t1\n";
    //     a.deleteCol(1);
    //     std::cout << a << std::endl;
    //     std::cout << "RESIZE ROWS TO \ta.GetRows() + 1\n";
    //     a.resizeRows(a.GetRows() + 1, 9);
    //     std::cout << a << std::endl;
    //     std::cout << "RESIZE COLS TO \ta.GetCols() + 1\n";
    //     a.resizeCols(a.GetCols() + 1, 9);
    //     std::cout << a << std::endl;
    //     std::cout << "RESIZE ROWS AND COLS TO \ta.GetRows() + 1   a.GetCols() + 1\n";
    //     a.resize(a.GetRows() + 1, a.GetCols() + 1);
    //     std::cout << a << std::endl;
    //     std::cout << "RESIZE ROWS AND COLS TO \ta.GetRows() - 2   a.GetCols() - 2\n";
    //     a.resize(a.GetRows() - 2, a.GetCols() - 2);
    //     std::cout << a;
    //     std::cout << std::endl << std::endl;
    // }


    // std::cout << "!!! ERROR SEGMENT !!!" << std::endl;
    // {
    //     std::cout << "!~Constructor with size below zero\n";
    //     try
    //     {
    //         Matrix<int> a(5, -1);
    //     }
    //     catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Wrong init list\n";
    //     try
    //     {
    //         Matrix<int> a = {{1, 2}, {3, 4, 5}};
    //     }
    //     catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Get non-exist column\n";
    //     Matrix<int> a(5, 5);
    //     try
    //     {
    //         a[3][100] = 4;
    //     }
    //     catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Get non-exist row\n";
    //     try
    //     {
    //         a[100][3] = 4;
    //     }
    //     catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Read expired iterator\n";
    //     try
    //     {
    //         Iterator<int> it = a.begin();
    //         {
    //             Matrix<int> buf = { { 1, 2 }, { 3, 4 } };
    //             it = buf.begin();
    //         }
    //         std::cout << *it;
    //     } catch (BaseException &err) {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Read iterator out of range\n";
    //     try
    //     {
    //         Iterator<int> it = a.end();
    //         std::cout << *it;
    //     } catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Sum of non-compatitve matrices\n";
    //     try
    //     {
    //         Matrix<int> b = {{1, 2}, {3, 4}};
    //         Matrix<int> c = {{1, 2}, {3, 4}, {5, 6}};
    //         b + c;
    //     } catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Mul of non-compatitive matrices\n";
    //     try
    //     {
    //         Matrix<int> b = {{1, 2}, {3, 4}};
    //         Matrix<int> c = {{1, 2}, {3, 4}, {5, 6}};
    //         b * c;
    //     } catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Div by zero val\n";
    //     try
    //     {
    //         Matrix<int> b = {{1, 2}, {3, 4}};
    //         int buf = 0;
    //         Matrix<int> c = b / buf;
    //     } catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    //     std::cout << "!~Init with error vectors\n";
    //     try
    //     {
    //         std::cout << "Constructor with vectors \tv { {1, 2}, {3, 4}, {5, 6, 7} } g(v):\n";
    //         std::vector<std::vector<int>> v { {1, 2}, {3, 4}, {5, 6, 7} };
    //         Matrix<int> g(v);
    //         std::cout << g << std::endl;
    //     } catch (BaseException &err)
    //     {
    //         std::cout << err.what() << std::endl;
    //     }
    // }

    // std::cout << "=== MATH WITH DIFF TYPE OF MATRIX ===" << std::endl;
    // {
    //     Matrix<int> a = {{5, 10}, {20, 25}};
    //     Matrix<float> b = {{-5, 4.5}, {2.5, 8}};
    //     Matrix<float> buf;
    //     buf = a + b;
    //     std::cout << "A + B \n" << buf << std::endl;
    //     buf = a - b;
    //     std::cout << "A - B \n" << buf << std::endl;
    //     buf = a * b;
    //     std::cout << "A * B \n" << buf << std::endl;
    //     buf = a - b;
    //     std::cout << "A / B \n" << buf << std::endl;
    //     buf = a.addMatrix(b);
    //     std::cout << "A + B (method) \n" << buf << std::endl;
    //     buf = a.subMatrix(b);
    //     std::cout << "A - B (method) \n" << buf << std::endl;
    //     buf = a.mulMatrix(b);
    //     std::cout << "A * B (method) \n" << buf << std::endl;
    //     buf = a.divMatrix(b);
    //     std::cout << "A / B (method) \n" << buf << std::endl;
    // }

    return 0;
}
