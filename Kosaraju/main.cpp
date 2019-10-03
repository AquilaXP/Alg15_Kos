#include <iostream>
#include <random>

#include "Kosaraju.h"

Graph5 generateGraph( size_t size )
{
    std::mt19937 mt;
    std::uniform_int_distribution<size_t> dist( 0, size );
    std::uniform_int_distribution<int32_t> distW( 0, ( std::numeric_limits<int32_t>::max )( ) );
    size_t maxS = size / 10;
    Graph5 graph( size, maxS );

    std::mt19937 mt2( rand() );
    std::uniform_int_distribution<size_t> dist2( 0, maxS );
    for( size_t i = 0; i < size; ++i )
    {
        size_t curS = dist2(mt2);
        for( size_t i = 0; i < curS; ++i)
            graph[i].add( { dist( mt ), distW( mt ) } );
    }

    return graph;
}

int main()
{
    try
    {
        std::vector< int > arr = { 1, 2, 3, 4, 6 , 8 };
        auto iter = std::lower_bound( arr.begin(), arr.end(), 10 );

        Graph5 graph( 8, 4 );

        graph[1].add( { 3, 5 } );
        graph[1].add( { 4, 3 } );
        graph[1].add( { 5, 4 } );
        graph[1].add( { 7, 1 } );
        graph[2].add( { 1, 1 } );
        graph[2].add( { 3, 1 } );
        graph[3].add( { 0, 1 } );
        graph[3].add( { 1, 1 } );
        graph[3].add( { 2, 1 } );
        graph[3].add( { 5, 1 } );
        graph[4].add( { 2, 1 } );
        graph[5].add( { 1, 1 } );
        graph[7].add( { 2, 1 } );
        graph[7].add( { 4, 1 } );

        auto res = KosarajuIter( graph );

        auto res2 = KosarajuRec( graph );

        bool r = ( *res == *res2 );
        if( r == false )
            throw std::runtime_error( "not equale iter and recursive result(1)" );
        Graph5 bigGraph = generateGraph( 10000 );
        
        res = KosarajuIter( graph );
        res2 = KosarajuRec( graph );

        r = ( *res == *res2 );
        if( r == false )
            throw std::runtime_error( "not equale iter and recursive result(2)" );
    }
    catch( const std::exception& e )
    {
    	
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

