#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

using namespace std;

class Matrix {
    friend ostream &operator<<( ostream &, const Matrix & );
    friend istream &operator>>( istream &, Matrix & );
public:
    Matrix( int = 3, int = 3 );         // default konstruktor
    Matrix( const Matrix & );             // copy konstruktor
    ~Matrix();                            // destruktor
    int getSize() const;                  // vrati golemina
    int getRows() const;                  // vrati broj na redovi
    int getCols() const;                  // vrati broj na koloni
    const Matrix &operator=( const Matrix & ); // dodeli dvodimenzionalni nizi
    bool operator==( const Matrix & ) const;  // sporedi ednakvi

    // Odredi dali dve dvodimenzionalni nizi se ednakvi i
    // vrati true, inaku vrati false (go koristi operator==).
    bool operator!=( const Matrix &right ) const
    { return ! ( *this == right ); }

    int* operator[]( int );              // indeksen operator
    const int* operator[]( int ) const;  // indeksen operator
    static int getMatrixCount();         // vrati broj na instancirani nizi.
private:
    int rows; // broj na redovi na dvodimenzionalnata niza
    int cols; // broj na koloni na dvodimenzionalnata niza
    int **ptr; // pokazhuvach do prviot elemen na dvodimenzionalnata niza
    static int matrixCount;  // # na instancirani nizi
}; // kraj na klasata Matrix

// Inicijaliziraj statichka promenliva
int Matrix::matrixCount = 0;   // seushte nema nitu eden objekt

// Konstruktor za klasata Matrix (predefinirana golenina e 10)
Matrix::Matrix( int matrixRows, int matrixCols )
{
    rows = ( matrixRows > 0 ? matrixRows : 10 );
    cols = ( matrixCols > 0 ? matrixCols : 10 );
    ptr = new int*[ rows ]; // sozdadi pokazuvaci za site redovi vo dvodimenzionalnata niza
    assert( ptr != 0 );     // zavrshi ako ne sme dobile dovolno memorija
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[ cols ];  // sozdadi mesto za sekoja kelija vo redot i
        assert( ptr[i] != 0 );     // zavrshi ako ne sme dobile dovolno memorija
    }
    ++matrixCount;          // izbroi ushte eden objekt

    for ( int i = 0; i < rows; i++ )
        for (int j = 0; j < cols; j++)
            ptr[ i ][ j ] = 0;          // inicijaliziraj dvodimenzionalna niza
} // kraj na konstruktorot na Matrix

// Copy konstruktor za klasata Matrix mora da dobie referenca za da se onevozmozhi beskonechna rekurzija
Matrix::Matrix( const Matrix &init ) : rows( init.rows ), cols( init.cols )
{
    ptr = new int*[ rows ]; // sozdadi pokazuvaci za site redovi vo dvodimenzionalnata niza
    assert( ptr != 0 );     // zavrshi ako ne sme dobile dovolno memorija
    for (int i = 0; i < rows; i++) {
        ptr[i] = new int[ cols ];  // sozdadi mesto za sekoja kelija vo redot i
        assert( ptr[i] != 0 );     // zavrshi ako ne sme dobile dovolno memorija
    }
    ++matrixCount;          // izbroi ushte eden objekt

    for ( int i = 0; i < rows; i++ )
        for (int j = 0; j < cols; j++)
            ptr[ i ][ j ] = init.ptr[ i ][ j ];  // kopiraj init vo objektot
} // kraj na konstruktorot na Matrix

// Destruktor za klasata Matrix
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++) {
        delete [] ptr[i];      // vrati ja memorijata na kolonite
    }
    delete [] ptr;             // vrati ja memorijata na redovite
    --matrixCount;             // eden objekt pomalku
} // kraj na destruktorot na Matrix

// Zemi gi dimenziite na dvodimenzionalnata niza
int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }
int Matrix::getSize() const { return rows*cols; }

// Preklopi go operatorot za dodeluvanje
// vrakjanje na const izbegnuva: ( a1 = a2 ) = a3
const Matrix &Matrix::operator=( const Matrix &right )
{
    if ( &right != this ) {  // proveri da ne ima samo-dodeluvanje

        // za nizi so razlichni golemini, dealociraj ja originalnata
        // niza od levata strana, potoa alociraj niva niza na levata strana.
        if ( rows != right.rows || cols != right.cols ) {
            for (int i = 0; i < rows; i++) {
                delete [] ptr[i];  // vrati ja memorijata na kolonite
            }
            delete [] ptr;         // vrati ja memorijata na redovite
            rows = right.rows;     // smeni go brojot na redovi na this objektot
            cols = right.cols;     // smeni go brojot na koloni na this objektot

            ptr = new int*[ rows ]; // sozdadi pokazuvaci za kopija na site redovi vo dvodimenzionalnata niza
            assert( ptr != 0 );     // zavrshi ako ne sme dobile dovolno memorija
            for (int i = 0; i < rows; i++) {
                ptr[i] = new int[ cols ];  // sozdadi mesto za kopija na sekoja kelija vo redot i
                assert( ptr[i] != 0 );     // zavrshi ako ne sme dobile dovolno memorija
            }
        } // kraj if

        for ( int i = 0; i < rows; i++ )
            for (int j = 0; j < cols; j++)
                ptr[ i ][ j ] = right.ptr[ i ][ j ];  // kopiraj dvodimenzionalna niza vo objekt
    } // kraj if

    return *this;   // ovozmozhuva x = y = z;
} // kraj na funkcijata operator=

// Odredi dali dve nizi se ednakvi i vrati true, inaku vrati false.
bool Matrix::operator==( const Matrix &right ) const
{
    if ( cols != right.cols || rows != right.rows )
        return false;    // dvodimenzionalni nizi so rezlicen broj na redovi ili koloni

    for ( int i = 0; i < rows; i++ )
        for (int j = 0; j < cols; j++)
            if ( ptr[ i ][ j ] != right.ptr[ i ][ j ] )
                return false; // nizite ne se ednakvi

    return true;        // nizite se ednakvi
} // kraj na funkcijata operator==

// Preklopen indeksen operator za ne-const nizi
// vrakjanjeto na referenca sozdava lvalue
int* Matrix::operator[]( int subscript )
{
    // proveri dali indeksite se vo potrebniot opseg
    assert( 0 <= subscript && subscript < rows );
    return ptr[ subscript ]; // vrati referenca
} // kraj na funkcijata operator[]

// Preklopi indeksen operator za const nizi
// vrakjanje na const referenca return sozdava rvalue
const int* Matrix::operator[]( int subscript ) const
{
    // proveri dali indeksite se vo potrebniot opseg
    assert( 0 <= subscript && subscript < rows );
    return ptr[ subscript ]; // vrakjanje na const referenca
} // kraj na funkcijata operator[]

// Vrati go brojot na instancirani objekti od klasata Matrix
// statichkite funkcii ne mozhat da bidat const
int Matrix::getMatrixCount() { return matrixCount; }

// Preklopi go operatorot za vlez za klasata Matrix;
// vnesuva vrednosti za celata niza.
istream &operator>>( istream &input, Matrix &a )
{
    for ( int i = 0; i < a.rows; i++ )
        for ( int j = 0; j < a.cols; j++ )
            input >> a.ptr[ i ][ j ];

    return input;   // ovozmozhuva cin >> x >> y;
} // kraj na funkcijata operator>>

// Preklopi go operatorot za izlez za klasata Matrix
ostream &operator<<( ostream &output, const Matrix &a )
{
    for ( int i = 0; i < a.rows; i++ ) {
        for ( int j = 0; j < a.cols; j++ ) {
            output << setw( 9 ) << a.ptr[ i ][ j ];
        }
        output << endl;
    }

    return output;   // ovozmozhuva cout << x << y;
} // kraj na funkcijata operator<<


int main()
{
    // seushte nema objekti
    cout << "# na instancirani nizi = " << Matrix::getMatrixCount() << '\n';

    // kreiraj dve nizi i ispechati go brojot na Matrix objekti
    Matrix integers1( 7, 3 ), integers2;
    cout << "# na instancirani nizi = " << Matrix::getMatrixCount() << "\n\n";

    // ispechati ja goleminata i sodrzhinata na integers1
    cout << "Goleminata na nizata integers1 e "
         << integers1.getSize()
         << "\nPo inicijalizacijata:\n"
         << integers1 << '\n';

    // ispechati ja goleminata i sodrzhinata na integers2
    cout << "Goleminata na nizata integers2 e "
         << integers2.getSize()
         << "\nPo inicijalizacijata:\n"
         << integers2 << '\n';

    // vnesi gi i ispechati gi integers1 i integers2
    cout << "Vnesi 30 celi broja:\n";
    cin >> integers1 >> integers2;
    cout << "Po vnesuvanjeto, nizite sodzhat:\n"
         << "integers1:\n" << integers1
         << "integers2:\n" << integers2 << '\n';

    // iskoristi go preklopeniot operator za neednakvost (!=)
    cout << "Presmetuvam: integers1 != integers2\n";
    if ( integers1 != integers2 )
        cout << "Ne se ednakvi\n";

    // sozdadi niza integers3 koristejki ja integers1 kako
    // inicijalizator; ispechati ja goleminata i sodrzhinata
    Matrix integers3( integers1 );

    cout << "\nGoleminata na nizata integers3 e "
         << integers3.getSize()
         << "\nNizata po inicijalizacijata:\n"
         << integers3 << '\n';

    // iskoristi go preklopeniot operator za dodeluvanje (=)
    cout << "Dodeli go integers2 na integers1:\n";
    integers1 = integers2;
    cout << "integers1:\n" << integers1
         << "integers2:\n" << integers2 << '\n';

    // iskoristi go preklopeniot operator za ednakvost (==)
    cout << "Presmetuvam: integers1 == integers2\n";
    if ( integers1 == integers2 )
        cout << "Ednakvi se\n\n";

    // iskoristi go preklopeniot indeksen operator za da sozdadesh rvalue
    cout << "integers1[5] e " << integers1[ 5 ][1] << '\n';

    // iskoristi go preklopeniot indeksen operator za da sozdadesh lvalue
    cout << "Dodeluvam 1000 na integers1[5]\n";
    integers1[ 5 ][1] = 1000;
    cout << "integers1:\n" << integers1 << '\n';

    // obid da se postavi indeks nadvor od rangott
    cout << "Obid za dodeluvanje na 1000 na integers1[15]" << endl;
    integers1[ 15 ][1] = 1000;  // GRESHKA: nadvor od rang

    return 0;
} // kraj na main
