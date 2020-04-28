#include <vector>
#include <iostream>

using namespace std;

template<class T>
void
_print(T arg) {
    cout << arg << " ";
}

template<class... Args>
void
log(Args... args) {
    int arr[] = { (_print(args), 0)... };
    cout << endl;
}

float
sum(vector<float> &array) {
    float s = 0;
    size_t i = 0;
    while (i < array.size()) {
        float n = array[i];
        s = s + n;
        i = i + 1;
    }
    return s;
}

void
ensure(bool condition, const string &message) {
    if (condition) {
        log("测试成功");
    } else {
        log(message);
    }
}

bool
floatEqual(float a, float b) {
    auto delta = 0.00001;
    return (a - b) < delta & (b - a) < delta;
}


void
testSum(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = sum(v1);
    ensure(floatEqual(s1, 10), "sum test error 1");
    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = sum(v2);
    ensure(floatEqual(s2, 21), "sum test error 2");
}



float
product(vector<float> &array) {
    float s = 1;
    size_t i = 0;
    while (i < array.size()) {
        float n = array[i];
        s = s * n;
        i += 1;
    }
    return s;
}


void
testProduct(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = product(v1);
    ensure(floatEqual(s1, 10), "sum test error 1");
    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = product(v2);
    ensure(floatEqual(s2, 21), "sum test error 2");
}

float
abs1(float n) {
    if (n < 0) {
        n = -n;
    };
    return n;
}


void
testAbs1(void) {
    float v1 = 1;
    float s1 = abs1(v1);
    ensure(floatEqual(s1, 1), "abs test error 1");
    float v2 = -1;
    float s2 = abs1(v2);
    ensure(floatEqual(s2, 1), "abs test error 2");
}



float 
average(vector<float> &array) {
    size_t i = array.size();
    float s = sum(array);
    float n = s / i;
    log(n);
    return n;
}



void
testAverage(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = average(v1);
    ensure(floatEqual(s1, 2.5), "average test error 1");
    vector<float> v2 = {1, 2, 3, 4, 5};
    float s2 = average(v2);
    ensure(floatEqual(s2, 3), "average test error 2");
}

// 参数是一个数字 n
// 返回以下序列的结果
// 1 - 2 + 3 - 4 + 5 ... n
float
sum1(vector<float> &array) {
    size_t i = 0;
    float s = 0;
    while (i < array.size()) {
        int n = array[i];
        if (n % 2 != 0) {
            s += n;
        } else {
            s -= n;
        }
        i += 1;
    }
    return s;
}


void
testSum1(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = sum1(v1);
    ensure(floatEqual(s1, -2), "average test error 1");
    vector<float> v2 = {1, 2, 3, 4, 5};
    float s2 = sum1(v2);
    ensure(floatEqual(s2, 3), "average test error 2");
}




int
sum2(int n) {
    size_t i = 2;
    float s = 1;
 
    while (i < n + 1) {
        if (i % 2 == 0) {
            s += i;
        } else {
            s -= i;
        }
        i += 1;
    }
    return s;
}

void
testSum2(void) {
    int v1 = 4;
    int s1 = sum2(v1);
    ensure(floatEqual(s1, 4), "average test error 1");
    int v2 = 5;
    int s2 = sum2(v2);
    ensure(floatEqual(s2, -1), "average test error 2");
}





int
fac1(int n) {
    int s = 1;
    int i = 1;
    while (i < n+1) {
        s *= i;
        i += 1;
    }
    return s;
}

void
testFac1(void) {
    int v1 = 4;
    int s1 = fac1(v1);
    ensure(floatEqual(s1, 24), "fac1 test error 1");
    int v2 = 5;
    int s2 = fac1(v2);
    ensure(floatEqual(s2, 120), "fac1 test error 2");
}





void
test() {
    // testSum();
    // testProduct();
    // testAbs1();
    // testAverage();
    // testMini1();
    // testSum1();
    // testSum2();
    testFac1();
}


int
main(int argc, const char *argv[]) {
    test();

    return 0;
}