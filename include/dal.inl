/**
 * DAL class implementation.
 *
 */

#include "dal.h"

/**
 * ---------------------------------------------------------------------------
 * Common methods from DAL.
 * ---------------------------------------------------------------------------
 */

// Construtor inicializa TAD.
template < typename Key , typename Data , typename KeyComparator >
DAL<Key,Data, KeyComparator>::DAL ( int _iMaxSz ) :
    mi_Length( 0 ),         // Tamanho logico.
    mi_Capacity( _iMaxSz ), // Guardar capacidade atual.
    mpt_Data( nullptr )
{
    if ( _iMaxSz < 0 )          // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[ _iMaxSz ]; // Tamanho maximo.
}

template <typename Key, typename Data, typename KeyComparator>
int DAL<Key, Data, KeyComparator>::compare(Key _x, Key _y) const {
    KeyComparator comparador;
    return comparador(_x, _y);
}

template < typename Key , typename Data , typename KeyComparator >
int DAL<Key,Data, KeyComparator>::_search( Key _x ) const{
    auto i(0);
    for (;i < mi_Length and mpt_Data[i].id != _x  ; ++i);
            
        return i;
            
};

template < typename Key , typename Data , typename KeyComparator >
bool DAL<Key,Data, KeyComparator>::remove( const Key & _x, Data & _result ){
    auto posicao = _search(_x);
    if (posicao != mi_Length)
    {
        _result = mpt_Data[posicao].info;
        mi_Length--;
        for (int i = posicao; i < mi_Length; ++i)
        {
            mpt_Data[i]=mpt_Data[i+1];
        }
        return true;
    }
    return false;
}


template < typename Key , typename Data , typename KeyComparator >
bool DAL<Key,Data, KeyComparator>::search( const Key & _x, Data & _result) const{
        	auto idx = _search( _x );
        	if (idx == mi_Length)
        	{
        		return false;
        	}
        	_result = mpt_Data[ idx ].info;

        	return true;
        }

template < typename Key , typename Data , typename KeyComparator >
bool DAL<Key,Data, KeyComparator>::insert( const Key & _novaId, const Data & _novaInfo ){
        	auto idx = _search( _novaId );

        	if (idx == mi_Capacity)
        	{
        		throw std::length_error("Dicionario cheio");
        		return true;
        	}
        	else
        	{
        		mpt_Data[mi_Length].id = _novaId;
        		mpt_Data[mi_Length].info = _novaInfo;
        		mi_Length ++;
        		return true;
        	}
        }
template < typename Key , typename Data , typename KeyComparator >
Key DAL<Key,Data, KeyComparator>::min( ) const{
    int menor = mpt_Data[0].id;
    for (int i = 0; i < mi_Length; ++i)
    {
        if (menor > mpt_Data[i].id)
            menor = mpt_Data[i].id;
    }

    return menor;

}

template < typename Key , typename Data , typename KeyComparator >
Key DAL<Key,Data, KeyComparator>::max( ) const{
    Key maior = mpt_Data[0].id;
    for (int i = 0; i < mi_Length; ++i)
    {
        if (maior < mpt_Data[i].id)
            maior = mpt_Data[i].id;
    }

    return maior;
}

template < typename Key , typename Data , typename KeyComparator >
bool DAL<Key,Data, KeyComparator>::sucessor( const Key & _x , Key & _y ) const{
    int pos = _search(_x);

        if (mpt_Data[pos+1].id == NULL){
            return false;
        }else{
            _y = mpt_Data[pos+1].id;
            return true;
        }
        
}

template < typename Key , typename Data , typename KeyComparator >
bool DAL<Key,Data, KeyComparator>::predecessor( const Key & _x , Key & _y ) const{
    int pos = _search(_x);

        if (mpt_Data[pos-1].id == NULL){
            return false;
        }else{
            _y = mpt_Data[pos-1].id;
            return true;
        }
}

/**
 * ---------------------------------------------------------------------------
 * Common methods from DSAL.
 * ---------------------------------------------------------------------------
 */
template < typename Key , typename Data , typename KeyComparator >
int DSAL<Key,Data, KeyComparator>::_search( const Key & _x) const{
    auto sz = DAL<Key,Data, KeyComparator>::mi_Length, l  = 0, r = sz - 1;
    
    while (l <= r) {
        int m = (l+r)/2;
        auto x = DAL<Key,Data, KeyComparator>::mpt_Data[m].id;
        auto com = DAL<Key,Data, KeyComparator>::compare(x,_x);

        if (com == 0)
            return m;
        else if (com < 0)
            l = m+1;
        else
            r = m-1;
    }

    return sz;
}


template < typename Key , typename Data , typename KeyComparator >
bool DSAL<Key,Data, KeyComparator>::remove(const Key &_x, Data &_y){
    auto &tamanho = DAL<Key,Data, KeyComparator>::mi_Length;
    auto &data = DAL<Key,Data, KeyComparator>::mpt_Data;
    auto posicao = _search(_x);

    if (posicao != tamanho)
    {
        _y = data[posicao].info;
        tamanho--;
        for (int i = posicao; i < tamanho; ++i)
        {
            data[i]=data[i+1];
        }
        return true;
    }
    return false;
}

template < typename Key , typename Data , typename KeyComparator >
bool DSAL<Key,Data, KeyComparator>::insert( const Key & _novaId, const Data & _novaInfo ){
            auto idx = _search( _novaId );

            if (idx == DAL<Key,Data, KeyComparator>::mi_Capacity)
            {
                throw std::length_error("Dicionario cheio");
                return true;
            }
            else
            {
                DAL<Key,Data, KeyComparator>::mpt_Data[DAL<Key,Data, KeyComparator>::mi_Length].id = _novaId;
                DAL<Key,Data, KeyComparator>::mpt_Data[DAL<Key,Data, KeyComparator>::mi_Length].info = _novaInfo;
                DAL<Key,Data, KeyComparator>::mi_Length ++;
                return true;
            }
}


template < typename Key , typename Data , typename KeyComparator >
Key DSAL<Key, Data, KeyComparator>::min( ) const {

    auto menor = DAL<Key,Data, KeyComparator>::mpt_Data[0].id;
    for (auto i(0); i < DAL<Key,Data, KeyComparator>::mi_Length; ++i)
    {
        if (menor > DAL<Key,Data, KeyComparator>::mpt_Data[i].id)
            menor = DAL<Key,Data, KeyComparator>::mpt_Data[i].id;
    }

    return menor;
}

template < typename Key , typename Data , typename KeyComparator >
Key DSAL<Key,Data, KeyComparator>::max( ) const {

    auto maior = DAL<Key,Data, KeyComparator>::mpt_Data[0].id;
    for (auto i(0); i < DAL<Key,Data, KeyComparator>::mi_Length; ++i)
    {
        if (maior < DAL<Key,Data, KeyComparator>::mpt_Data[i].id)
            maior = DAL<Key,Data, KeyComparator>::mpt_Data[i].id;
    }

    return maior;
}

template < typename Key , typename Data , typename KeyComparator >
bool DSAL<Key,Data, KeyComparator>::sucessor( const Key & _x , Key & _y ) const{
    int pos = _search(_x);

        if (DAL<Key,Data, KeyComparator>::mpt_Data[pos+1].id == NULL){
            return false;
        }else{
            _y = DAL<Key,Data, KeyComparator>::mpt_Data[pos+1].id;
            return true;
        }
        
}

template < typename Key , typename Data , typename KeyComparator >
bool DSAL<Key,Data, KeyComparator>::predecessor( const Key & _x , Key & _y ) const{
    int pos = _search(_x);

        if (DAL<Key,Data, KeyComparator>::mpt_Data[pos-1].id == NULL){
            return false;
        }else{
            _y = DAL<Key,Data, KeyComparator>::mpt_Data[pos-1].id;
            return true;
        }
}
