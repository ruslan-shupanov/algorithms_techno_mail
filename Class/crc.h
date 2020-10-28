#pragma once
// Использование:
// CRCCoder<unsigned> crc32;
//    auto hash = crc32.calc("MyString", 8);
// 
//   Второй вариант:
//      for (auto c: "MyString") {
//          crc32.update(c);
//      } 
//      auto hash = crc32.final();
template<typename T>
class CRCCoder {
public:
    CRCCoder() {
        init();
    }

    static T calc(const void* data, unsigned size) {
        initTable();
        const unsigned char *p = reinterpret_cast<const unsigned char *>(data);
        T ctmp = T(-1);
        while (size) {
            ctmp ^= (T)(p[0]);
            ctmp = (ctmp >> 8) ^ _table[ctmp & 0xFF];
            p++;
            size--;
        }
        return ctmp ^ T(-1);
    }

    void init() {
        initTable();
        _value = T(-1);
    }

    void update(unsigned char p) {
        _value ^= (T)(p);
        _value = (_value >> 8) ^ _table[_value & 0xFF];
    }

    T final() {
        return _value ^ T(-1);
    }

private:
    T _value;
    static T _table[256];
    static T POLY;
    static void initTable() {
        if (_table[0] == 0) {
            T *p = _table;
            int             i, j;
            for (j = 0; j < 256; j++) {
                T x = j;
                for (i = 0; i < 8; i++) {
                    if ((x & 1) != 0) {
                        x = (x >> 1) ^ 0xC96C5795D7870F42ULL;
                    } else {
                        x = (x >> 1);
                    }
                }
                *p++ = x;
            }
        }
    }
};

template<> unsigned long long CRCCoder<unsigned long long>::POLY = 0xC96C5795D7870F42ULL;
template<> unsigned CRCCoder<unsigned>::POLY = 0xEDB88320U;
template<> unsigned long long CRCCoder<unsigned long long>::_table[256] = { 0 };
template<> unsigned CRCCoder<unsigned>::_table[256] = { 0 };