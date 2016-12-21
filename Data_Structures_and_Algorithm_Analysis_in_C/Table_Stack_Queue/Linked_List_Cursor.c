#include "Linked_List_Cursor.h"
#include <stdlib.h>

//Palce in the implememtation file
struct Node
{
    ElementType Element;
    Position    Next;
};
struct Node CursorSpace[ SpaceSize ];


static Position CursorAlloc( void )
{
    Position P;

    P = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = CursorSpace[ P ].Next;

    return P;
}

static void CursorFree( Position P )
{
    CursorSpace[ P ].Next = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = P;
}


void InitializeCursorSpace( void )
{
    int i;
    for( i = 0; i < SpaceSize; i++)
        CursorSpace[i].Next = i + 1;
    CursorSpace[i-1].Next = 0;
}

List MakeEmpty( List L)
{
    if( L != NULL)
        DeleteList( L );
    L = CursorAlloc();
    if ( L = 0 )
        Error("Out of memory!");
    CursorSpace[L].Next = 0;
    return L;
}

//Return True if List L is empty
int isEmpty( List L )
{
    return CursorSpace[L].Next == 0;
}

//Return P is the last position in list L
int isLast( Position P, Lint L )
{
    return CursorSpace[P].Next == 0;
}

//Return Position of ElementType X in List L,0 if not found
//Uses a header Node
Position Find( ElementType X, List L)
{
    Position P;
    P = CursorSpace[P].Next;
    while( P && CursorSpace[p].Element != X)
        P = CursorSpace[P].Next;
    return P;
}

//Delete from a list
// assume that the position is illegal
// assume use a header node
void Delete( ElementType X, List L )
{
    Position P, TmpCell;
    P = FindPrevious( X, L );
    if( !isLast( P, L ) )
    {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorSpace( TmpCell );
    }
}

//If X is not found, Then the next field of returned value is 0
Position FindPrevious( ElementType X, List L )
{
    Position P;
    P = L;
    while( CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
        P = CursorSpace[P].Next;
    return P;
}

//Insert
void Insert( ElementType X, List L, Position P )
{
    Position TmpCell;
    TmpCell = CursorAlloc();
    if(TmpCell == 0)
        Error("Out of Space!");
    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}

//Corret DeleteList algorithm
void DeleteList( List L )
{
    Position P, Tmp;
    P = CursorSpace[L].Next;  //header assumed
    CursorSpace[L].Next = 0;
    while( P != )
    {
        Tmp = CursorSpace[P].Next;
        CursorSpace(P);
        P = Tmp;
    }
}

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return CursorSpace[L].Next;
}

Position Advance( Position P )
{
    return CursorSpace[P].Next;
}

ElementType Retrieve( Position P )
{
    return CursorSpace[P].Element;
}