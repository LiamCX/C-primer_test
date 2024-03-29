#include <iostream>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;
using std::cout;
using std::endl;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data( make_shared<vector<string>>() ) { }
    StrBlob( initializer_list<string> il ) : data( make_shared<vector<string>>( il ) )  { }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back( const string &e ) { data->push_back( e ); }
    void pop_back() {
        check( 0, "pop_back on empty StrBlob");
        return data->pop_back();
    }

    string& front() {
        check( 0, "front on empty StrBlob");
        return data->front();
    }

    string& back() {
        check( 0, "back on empty StrBlob");
        return data->back();
    }

    string& front() const {
        check( 0, "front on empty StrBlob");
        return data->front();
    }

    string& back() const {
        check( 0, "back on empty StrBlob");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;
    void check( size_type i, const string &msg ) const {
        if( i >= data->size() )
            throw out_of_range( msg );
    }
};

int main() {
    StrBlob str{"se", "tr", "OK" };
    StrBlob a;
    cout << "size = " << str.size() << endl;
    cout << "front = " << a.front() << endl;
    cout << "back = " << str.back() << endl;

    return 0;
}
