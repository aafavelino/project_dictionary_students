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
template < typename Key, typename Data >
DAL<Key,Data>::DAL ( int _iMaxSz ) :
    mi_Length( 0 ),         // Tamanho logico.
    mi_Capacity( _iMaxSz ), // Guardar capacidade atual.
    mpt_Data( nullptr )
{
    if ( _iMaxSz < 0 )          // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[ _iMaxSz ]; // Tamanho maximo.
}

template < typename Key, typename Data >
int DAL<Key,Data>::_search( Key _x ) const{
    auto i(0);
    for (;i < mi_Length and mpt_Data[i].id != _x  ; ++i);
            
        return i;
            
};

template < typename Key, typename Data >
bool DAL<Key,Data>::remove( const Key & _x, Data & _result ){
        	auto idx = _search( _x );
        	if (idx == mi_Length)
        	{
        		return false;
        		_result = idx;
        	}
        	for (int i = _result; i < mi_Length; ++i)
        	{
        		mpt_Data[ i ].id = mpt_Data[ i+1 ].id;
        		mpt_Data[ i ].info = mpt_Data[ i+1 ].info;
        	}

        	mi_Length --;

        	return true;
        }


template < typename Key, typename Data >
bool DAL<Key,Data>::search( const Key & _x, Data & _result) const{
        	auto idx = _search( _x );
        	if (idx == mi_Length)
        	{
        		return false;
        	}
        	_result = mpt_Data[ idx ].info;

        	return true;
        }

template < typename Key, typename Data >
bool DAL<Key,Data>::insert( const Key & _novaId, const Data & _novaInfo ){
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
template < typename Key, typename Data >
Key DAL<Key,Data>::min( ) const{
    int menor = mpt_Data[0].id;
    for (int i = 0; i < mi_Length; ++i)
    {
        if (menor > mpt_Data[i].id)
            menor = mpt_Data[i].id;
    }

    return menor;

}

template < typename Key, typename Data >
Key DAL<Key,Data>::max( ) const{
    Key maior = mpt_Data[0].id;
    for (int i = 0; i < mi_Length; ++i)
    {
        if (maior < mpt_Data[i].id)
            maior = mpt_Data[i].id;
    }

    return maior;
}

template < typename Key, typename Data >
bool DAL<Key,Data>::sucessor( const Key & _x , Key & _y ) const{
    int pos = _search(_x);

        if (mpt_Data[pos+1].id == NULL){
            return false;
        }else{
            _y = mpt_Data[pos+1].id;
            return true;
        }
        
}

template < typename Key, typename Data >
bool DAL<Key,Data>::predecessor( const Key & _x , Key & _y ) const{
    int pos = _search(_x);

        if (mpt_Data[pos-1].id == NULL){
            return false;
        }else{
            _y = mpt_Data[pos-1].id;
            return true;
        }
}