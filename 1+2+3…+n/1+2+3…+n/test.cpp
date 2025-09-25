#define _CRT_SECURE_NO_WARNINGS 1

//初始
class Sum {
public:
    Sum()
    {
        _ret += _i;
        _i++;
    }
    static int Get_Sum()
    {
        return _ret;
    }
private:
    static int _ret;
    static int _i;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Sum arr[n];//变长数组
        return Sum::Get_Sum();
    }
};


//设计成内部类
class Solution {
    class Sum {
    public:
        Sum() {
            _ret += _i;
            _i++;
        }
    };

public:
    int Sum_Solution(int n) {
        Sum arr[n];//要变长数组
        return _ret;
    }
private:
    static int _ret;
    static int _i;
};
int Solution::_i = 1;
int Solution::_ret = 0;