class DSAL : public DAL // Indicação de herança
{

public:
DSAL( int _MaxSz ) : DAL( _MaxSz ) { /* Empty */ };

virtual ~DSAL() { /* Empty */ }; // Métodos para sobrescrever.

bool remove( const Key & _x, Data & );

bool insert( const Key & _novaId, const Data & _novaInfo ); 

Key min( ) const; // Recupera a menor chave do dicionário.

Key max( ) const; // Recupera a maior chave do dicionário. 

// Recupera em _y a chave sucessora a _x, se existir (true).
bool sucessor( const Key & _x, Key & _y ) const;

// Recupera em _y a chave antecessora a _x, se existir (true). 
bool predecessor( const Key & _x, Key & _y ) const;

private:
int _search( const Key & _x ) const; // Método de busca auxiliar.
};