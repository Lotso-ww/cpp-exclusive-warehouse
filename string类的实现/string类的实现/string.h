#pragma once
#include<iostream>
#include<assert.h>
#include<algorithm>
#include<string.h>
using namespace std;

namespace Lotso
{
    class string
    { 
    public:

        string(const char* str = "");
        string(const string& s);
        const char* c_str()const
        {
            return _str;
        }
        string& operator=(const string& s);
        ~string();

        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        void resize(size_t n, char c = '\0');

        void reserve(size_t n);

     //////////////////////////////////////////////////////////////

        typedef char* iterator;
        typedef const char* const_iterator;
        // iterator
        iterator begin()
        {
            return _str;
        }
        
        const_iterator begin() const
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const_iterator end() const
        {
            return _str + _size;
        }

        // access

        char& operator[](size_t index)
        {
            assert(index < _size);
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            assert(index < _size);
            return _str[index];
        }
      /////////////////////////////////////////////////////////////

        // modify
        void push_back(char ch);
        void append(const char* str);
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        void insert(size_t pos, char ch);
        void insert(size_t pos, const char* str);


        void swap(string& s);

        //bool empty()const;    

        /////////////////////////////////////////////////////////////

            //relational operators
            bool operator<(const string& s) const;
            bool operator<=(const string& s) const;
            bool operator>(const string& s) const;
            bool operator>=(const string& s) const;
            bool operator==(const string& s) const;
            bool operator!=(const string& s) const;
            
        // 返回ch在string中第一次出现的位置
        size_t find(char ch, size_t pos = 0) const;


        // 返回子串str在string中第一次出现的位置
        size_t find(const char* str, size_t pos = 0) const;


        // 删除pos位置上的元素，并返回该元素的下一个位置
        void erase(size_t pos = 0, size_t len = npos);

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        string substr(size_t pos=0, size_t len=npos);

    private:
        char* _str;
        size_t _capacity;
        size_t _size;

    public:
        //这里比较特殊，const static整型可以这么用，特殊处理
        //当然也可以声明和定义分离
        const static size_t npos = -1;
        //const static double npos=-1;//这个是不行的
    };

    std:: ostream& operator<<(ostream& _cout, const string& s);
    std:: istream& operator>>(istream& _cin, string& s);
    std::istream& getline(std::istream& in, string& s, char delim = '\n');

    template <class T>
    void swap(T& a, T& b)
    {
        T c(a); a = b; b = c;
    }

    inline void swap(string& a, string& b)
    {
        //还是调的库里的
        a.swap(b);
    }
};


