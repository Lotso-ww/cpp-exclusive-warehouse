#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

namespace Lotso
{
    void string::swap(string& s)
    {
        //直接交换资源
        std::swap(_str, s._str);
        std::swap(_size, s._size);
        std::swap(_capacity, s._capacity);

    }
    string::string(const char* str)//.h里面给缺省值
        :_size(strlen(str))
        {
            //_size = strlen(str);//这个写里面也可以
            //初始化列表初始化顺序跟声明顺序有关
            //所以这里写在函数体里比较好，可以灵活使用size
            _str = new char[_size + 1];//多开一个给\0;
            _capacity = _size;
            strcpy(_str, str);
        }
    string::~string()
    {
        delete[] _str;
        _str = nullptr;
        _size = 0;
        _capacity = 0;
    }
    //string s2(s1);
    string::string(const string& s)
    {
        _str = new char[s._capacity + 1];
        //strcpy(_str, s._str);//这里可以用strcpy，但是memcpy更好
        memcpy(_str, s._str, s._size + 1);
        _size = s._size;
        _capacity = s._capacity;
    }
    

    //s1=s3
    string& string::operator =(const string& s)
    {
        if (this != &s)
        {
            char* tmp = new char[s._capacity + 1];
            //strcpy(_str,s._str);
            //这里用memcpy是因为处理串里中间有\0的情况；
            memcpy(tmp, s._str, s._size + 1);

            delete[] _str;
            _str = tmp;
            _size = s._size;
            _capacity=s._capacity;
        }
        return *this;
    }

    // 预留内存空间，只改变容量，不改变有效字符数
    void string::reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];
            //strcpy(tmp, _str);
            memcpy(tmp, _str, _size + 1);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }

    // 调整有效字符长度，可指定填充字符
    void string::resize(size_t n, char ch)
    {
        if (n <= _size)
        {
            //删除，保留前n个
            _size = n;
            _str[_size] = '\0';
        }
        else {
            reserve(n);
            for (size_t i = _size; i < n; i++)
            {
                _str[i] = ch;
            }
            _size = n;
            _str[_size] = '\0';
        }
    }

    void string::push_back(char ch)
    {
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
        _str[_size] = ch;
        _size++;
        _str[_size] = '\0';
    }
    void string::append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            //这样扩容比较好，每次插入的短就会2倍扩，多就会直接扩_size+len
            reserve(max(_size + len, 2 * _capacity));
        }
        //strcpy(_str + _size, str);
        memcpy(_str + _size, str, len + 1);
        _size += len;
    }

   // const size_t string::npos = -1;

    void string::insert(size_t pos, char ch)
    {
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
        //移动数据
        //int end = _size;//不能用size_t
        //while (end >= (int)pos)//强转一下
        //{
        //    _str[end + 1] = _str[end];
        //    --end;
        //}

        size_t end = _size+1;
        while (end >pos)//强转一下
        {
            _str[end] = _str[end-1];
            --end;
        }
        _str[pos] = ch;
        _size++;
    }

    void string::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            //这样扩容比较好，每次插入的短就会2倍扩，多就会直接扩_size+len
            reserve(max(_size + len, 2 * _capacity));
        }
        /*int end = _size;
        while (end >= (int)pos)
        {
            _str[end + len] = _str[end];
            --end;
        }*/
        size_t end = _size + len;
        while (end > pos + len - 1)
        {
            _str[end] = _str[end - len];
            --end;
        }

        //strncpy(_str + pos, str, len);
        memcpy(_str + pos, str, len);
        _size += len;
    }


    void string::erase(size_t pos, size_t len)
    {
        assert(pos <= _size);

        if (len == npos || len >= _size - pos)
        {
            //删完
            _size = pos;
            _str[_size] = '\0';
        }
        else {
            //删部分
            //strcpy(_str + pos, _str + pos + len);
            memcpy(_str + pos, _str + pos + len, _size - (pos + len) + 1);

            _size -= len;
        }
    }

    size_t string::find(char ch, size_t pos) const
    {
        assert(pos < _size);
        for (size_t i = pos; i < _size; i++)
        {
            if (_str[i] == ch)
            {
                return i;
            }
        }
        return npos;
    }

    size_t string::find(const char* str, size_t pos) const
    {
        assert(pos < _size);

        //大家也可以看看一个算法，我这里挂上链接
        //https://www.bilibili.com/video/BV1UL411E7M8/?spm_id_from=333.1387.list.card_archive.click&vd_source=e76166931683eb6cd68b7efecd0cdfc0
        const char* ptr = strstr(_str + pos, str);
        if (ptr)
        {
            return ptr - str;
        }
        else {
            return npos;
        }
    }

    string string::substr(size_t pos, size_t len)
    {
        assert(pos < _size);
        if (len == npos || len > _size - pos)
        {
            len = _size - pos;
        }
        string sub;
        sub.reserve(len);
        for (size_t i = 0; i < len; i++)
        {
            sub += _str[pos + i];
        }
        return sub;
    }

    bool string::operator<(const string& s) const
    {
        return strcmp(_str, s._str) < 0;
    }
    bool string::operator<=(const string& s) const
    {
        return *this < s || *this == s;
    }
    bool string::operator>(const string& s) const
    {
        return !(*this <= s);
    }
    bool string::operator>=(const string& s) const
    {
        return !(*this < s);
    }
    bool string::operator==(const string& s) const
    {
        return strcmp(_str, s._str) == 0;
    }
    bool string::operator!=(const string& s) const
    {
        return !(*this == s);
    }

    //流插入（输出）：将字符串内容写入输出流
    std::ostream& operator<<(std::ostream& out, const string& s)
    {
        for (auto ch : s)
        {
            out << ch;
        }

        return out;
    }

    //流提取（输入）：从输入流读取到空白字符为止
    std::istream& operator>>(std::istream& in, string& s)
    {
        s.clear();//先清空原有内容

        char buff[256];
        int i = 0;

        char ch;
        //in>>ch;
        //这个不行，读不了空格
        ch = in.get();
        while (ch != '\n' && ch != ' ')
        {
            buff[i++] = ch;
            if (i == 255)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }

            ch = in.get();
        }
        //要是没有255就这样处理
        if (i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }

    //整行读取：读取到指定分隔符（默认'\n'）为止
    std::istream& getline(std::istream& in, string& s, char delim)
    {
        s.clear();

        char buff[256];
        int i = 0;

        char ch;
        //in>>ch;
        //这个不行，读不了空格
        ch = in.get();
        while (ch != delim)
        {
            buff[i++] = ch;
            if (i == 255)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }

            ch = in.get();
        }
        //要是没有255就这样处理
        if (i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }
};



