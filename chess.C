#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int pwstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; //white pawn first movement 
int pbstatus[8] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; //black pawn first movement

char board[8][8] = {
                    { 'R' , 'H' , 'C' , 'K' , 'Q' , 'C' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'c' , 'k' , 'q' , 'c' , 'h' , 'r' }
                    };

void display();
void change( int , int , int , int ) ;
void pawn(int , int ) ;
void rook(int , int ) ;
void horse(int , int ) ;
void camel( int , int ) ;
void king( int , int ) ;
void queen( int , int ) ;
void pawnb( int , int ) ;
void player1();
void player2();
void help();
int check(int , int ) ;
int check2(int , int ) ;
int check3(int , int ) ;


int turn =0;

int killw=0; int killb=0;

int lim[100]={};

main()
{
//int  x = 0 ;
char ch ;
	
	system ("color 06");
	
    printf( "\n\tWELCOME TO CHESS GAME" ) ;
    printf( "\n\n\t By Hosseini, Shaker " ) ;
	
	 printf("\n\n If you want to change the font or background click \n\n1.Background    .  \n2.Text   .   \n3.Both...... \nenter any\
other number to exit.......... \n");
    fflush(stdin);
    scanf("%d",&user);
    switch(user)
    {
    case 1:
                help();
                printf("\n\n choose any color code for background ....");
                fflush(stdin);
          scanf("%c",&x[6]);
          while(x[7] == '\0'){x[7] = '0';}
          system(x);
          break;

     case 2:
        help();
           printf(" \n\n choose any color code for text ...  ");
       while(x[6] == '\0'){ x[6] = '0';}
    fflush(stdin);
    scanf("%c",&x[7]);
    system(x);
    break;
     case 3:
        help();
        printf(" \n\n color code for background...  =  ");
    fflush(stdin);
    scanf("%c",&x[6]);
    printf(" \n\n color code for text...  =  ");
    fflush(stdin);
    scanf("%c",&x[7]);
    system(x);
        break;
default :
        printf("\n\n do you want to exit.......?(y/n)   ");
        char ch;
        fflush(stdin);
        scanf("%c",&ch);
        if(ch == 'y' || ch == 'Y')
        {
            system("cls");
            printf("\nHAVE A GOOD DAY........\n\n");
            exit(0);
        }
        break;
    }
	
    getch();
    system( "cls" ) ;
    

 do
 {
 turn++ ;
 system( "cls" ) ;
 display();

 if( (turn%2) == 0 )
 {
            player2();
 }
 else
 {
     player1();
 }

 printf( " \n\nPress Enter To Continue ! \n\n " ) ;

 ch = getch();
 }while( ch == 13 ) ;

}

void help()
{
     printf("\n\n    0 = Black       8 = Gray\n\
    1 = Blue        9 = Light Blue\n\
    2 = Green       A = Light Green\n\
    3 = Aqua        B = Light Aqua\n\
    4 = Red         C = Light Red\n\
    5 = Purple      D = Light Purple\n\
    6 = Yellow      E = Light Yellow\n\
    7 = White       F = Bright White ");
}

void display()
{
    int i , j , k ;

    printf( " " ) ;
    for( i=0 ; i<8 ; i++ ) printf( "    %d" , i ) ; printf( "\n" ) ;

    for( k=0 ; k<8 ; k++ )
    {
    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ; printf( "%d " , k ) ;

    for( j=0 ; j<8 ; j++ ) { printf( "|| %c " , board[k][j] ) ; }
    printf( "|| \n" ) ;
    }

    printf( "  " ) ;
    for( i=0 ; i<42 ; i++ ) { printf( "-" ) ; } printf( "\n" ) ;

}

void change( int r1 , int c1 , int r2 , int c2 )
{
    char temp ;

    temp = board[r1][c1] ;
    board[r1][c1] = board[r2][c2] ;
    board[r2][c2] = temp ;

}

void pawn( int r1 , int c1 ) // paido
{
    int i;
    
	pwstatus[c1]++;
	
	
	for (i=0;i<100;++i){
		lim[i]=0;
	}
	
	i=0;
	
    printf( "Available are: \n" ) ;

   if( pwstatus[c1] == 1 )
    {
        if( board[r1+1][c1] == ' ' ){
        	printf( "%d%d , " , r1+1 , c1 ) ;
        	lim[i]=((r1+1)*10)+c1;
        	++i;
    	}

        if( board[r1+2][c1] == ' ' ){
        	printf( "%d%d , " , r1+2 , c1 ) ;
			lim[i]=((r1+2)*10)+c1;
        	++i;
		}
	
    }
    else
    {
        if(board[r1+1][c1] == ' ' ){
        	printf( "%d%d , " , r1+1 , c1 ) ;
        	lim[i]=((r1+1)*10)+c1;
        	++i;
		}
        if( check(r1+1 , c1+1) == 1 ){
        	printf( "%d%d* , " , r1+1 , c1+1 ) ;
        	lim[i]=((r1+1)*10)+(c1+1);
        	++i;
		}
        if( check(r1+1 , c1-1) == 1 ){
        	printf( "%d%d* , " , r1+1 , c1-1 ) ;
        	lim[i]=((r1+1)*10)+(c1-1);
        	++i;
		}
	
	
	}

}

void rook( int r1 , int c1 )
{
    int i , j , n , k=0;

    printf( "Available are: \n" ) ;

    n=c1;
	
    printf( "Horizontally: \n" ) ;

    while( board[r1][n-1] == ' ' || check3(r1,n-1) )
    {
        if( n == 0 ) { break ; }
        printf( "%d%d , " , r1 , n-1 ) ;
        lim[k]=(r1*10)+(n-1);
        ++k;
        n-- ;
    }

    n=c1 ;

    while( ( board[r1][n+1] == ' ' || check3(r1,n+1) ) && (n+1) <= 7 )
    {

        printf( "%d%d , " , r1 , n+1 ) ;
        lim[k]=(r1*10)+(n+1);
        ++k;
        ++n ;
    }

    printf( "\nVertically:\n" ) ;

    n = r1 ;

    while( ( board[n-1][c1] == ' ' || check3(n-1,c1) ) && n > -1 )
    {
        printf( "%d%d , " , n-1 , c1 ) ;
        lim[k]=((n-1)*10)+c1;
        ++k;
        --n ;
    }

    n = r1 ;

    while( (board[n+1][c1] == ' ' || check3(n+1,c1) ) && ( (n) <= 7 ) )
    {
        printf( "%d%d , " , n+1 , c1 ) ;
        lim[k]=((n+1)*10)+c1;
        ++k;
        ++n ;
    }

}

void horse( int r1 , int c1 )
{
	int i=0;
    printf( "Available are: " ) ;


    if( board[r1+2][c1+1] == ' ' || check3(r1+2,c1+1) ){
		printf( "%d%d, " , r1+2 ,c1+1) ;
		lim[i]=((r1+2)*10)+(c1+1);
		++i;
	}
    if( board[r1+2][c1-1] == ' ' || check3(r1+2,c1-1) ) { 
		if( (c1-1) > -1 ){
			printf( "%d%d, " , r1+2, c1-1 ) ; 
			lim[i]=((r1+2)*10)+(c1-1);
			++i;
		}
	}

    if( board[r1+1][c1+2] == ' ' || check3(r1+1,c1+2) ) {  
		if( (c1+2) != 8 ){
			printf( "%d%d, " , r1+1 , c1+2 ) ;
			lim[i]=((r1+1)*10)+(c1+2);
			++i;
		}
	}
    if( board[r1-1][c1+2] == ' ' || check3(r1-1,c1+2) ) {  
		printf( "%d%d, " , r1-1 , c1+2 ) ; 
		lim[i]=((r1-1)*10)+(c1+2);
		++i;
	}

    if( board[r1-2][c1-1] == ' ' || check3(r1-2,c1-1) )
    {
        if( (c1-1) != -1 ){
        	printf( "%d%d, " , r1-2 , c1-1 ) ;
        	lim[i]=((r1-2)*10)+(c1-1);
        	++i;
    	}
    }

    if( board[r1-2][c1+1] == ' ' || check3(r1-2,c1+1) ) {
		printf( "%d%d, " , r1-2 , c1+1 ) ;
		lim[i]=((r1-2)*10)+(c1+1);
		++i;
	}

    if( board[r1+1][c1-2] == ' ' || check3(r1+1,c1-2) ) {
		printf( "%d%d, " , r1+1 , c1-2 ) ;
		lim[i]=((r1+1)*10)+(c1-2);
		++i;
	}

    if( board[r1-1][c1-2] == ' ' || check3(r1-1,c1-2) )
    {
        if( (c1-2) != -1 ){
            printf( "%d%d, " , r1-1 , c1-2 ) ;
        	lim[i]=((r1-1)*10)+(c1-2);
			++i;  
        }
    }
}


void camel( int r1 , int c1 )
{
    int a , b , c , d , i=0;
    printf( "Available are: \n" ) ;


    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' || check3(r1-a,c1+b) )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        lim[i]=((r1-a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' || check3(r1+a,c1-b) )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        lim[i]=((r1+a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' || check3(r1+a,c1+b) )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        lim[i]=((r1+a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' || check3(r1-a,c1-b) )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        lim[i]=((r1-a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

}

void king( int r1 , int c1 )
{
	int i=0;
    printf( "Available are: " ) ;
								
    if( board[r1][c1+1] == ' ' || check3(r1,c1+1) ) {
		printf( "%d%d , " , r1 , c1+1 ) ;
		lim[i]=((r1)*10)+(c1+1);
		++i;
	}

    if( board[r1][c1-1] == ' ' || check3(r1,c1-1) ) {
		printf( "%d%d , " , r1 , c1-1 ) ;
		lim[i]=((r1)*10)+(c1-1);
		++i;
	}

    if( board[r1+1][c1] == ' ' || check3(r1+1,c1) ) {
		printf( "%d%d , " , r1+1 , c1 ) ;
		lim[i]=((r1+1)*10)+(c1);
		++i;
	}

    if( board[r1-1][c1] == ' ' || check3(r1-1,c1) ) {
		printf( "%d%d , " , r1-1 , c1 ) ;
		lim[i]=((r1-1)*10)+(c1);
		++i;
	}

    if( board[r1+1][c1+1] == ' ' || check3(r1+1,c1+1) ) {
		printf( "%d%d , " , r1+1 , c1+1 ) ;
		lim[i]=((r1+1)*10)+(c1+1);
		++i;
	}

    if( board[r1-1][c1-1] == ' ' || check3(r1-1,c1-1) ) {
		printf( "%d%d , " , r1-1 , c1-1 ) ;
		lim[i]=((r1-1)*10)+(c1-1);
		++i;
	}

    if( board[r1-1][c1+1] == ' ' || check3(r1-1,c1+1) ) {
		printf( "%d%d , " , r1-1 , c1+1 ) ;
		lim[i]=((r1-1)*10)+(c1+1);
		++i;
	}

    if( board[r1+1][c1-1] == ' ' || check3(r1+1,c1-1) ) {
		printf( "%d%d , " , r1+1 , c1-1 ) ;
		lim[i]=((r1+1)*10)+(c1-1);
		++i;
	}
    
    
}

void queen( int r1 , int c1 )
{
    int x=1 , y=1 , a , b , i=0;
    printf( "Available are: " ) ;

    printf( "Horizontal: " ) ;

    while( board[r1][c1-y] == ' ' || check3(r1,c1-y) )
    {
        if( (c1-y) == -1 ) break ;
        printf( "%d%d , " , r1 , c1-y ) ;
        lim[i]=((r1)*10)+(c1-y);
        ++i;
        y++ ;
    }

    y = 1 ;

    while( board[r1][c1+y] == ' ' || check3(r1,c1+y) )
    {
        if( (c1+y) == 8 ) break ;
        printf( "%d%d , " , r1 , c1+y ) ;
        lim[i]=((r1)*10)+(c1+y);
        ++i;
        y++ ;
    }

    printf( "Vertical: " ) ;

    x = 1 ;

    while( board[r1-x][c1] == ' ' || check3(r1-x,c1) )
    {
        if( (r1-x) == -1 ) break ;
        printf( "%d%d , " , r1-x , c1 ) ;
        lim[i]=((r1-x)*10)+(c1);
        ++i;
        x++ ;
    }

    x = 1 ;

    while( board[r1+x][c1] == ' ' || check3(r1+x,c1) )
    {
        if( (r1+x) == 8 ) break ;
        printf( "%d%d , " , r1+x , c1 ) ;
        lim[i]=((r1+x)*10)+(c1);
        ++i;
        x++ ;
    }

    printf( "Diagonally: " ) ;

    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' || check3(r1-a,c1+b) )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1-a , c1+b ) ;
        lim[i]=((r1-a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' || check3(r1+a,c1-b) )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1+a , c1-b ) ;
        lim[i]=((r1+a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' || check3(r1+a,c1+b) )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
        printf( "%d%d , " , r1+a , c1+b ) ;
        lim[i]=((r1+a)*10)+(c1+b);
        ++i;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' || check3(r1-a,c1-b) )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
        printf( "%d%d , " , r1-a , c1-b ) ;
        lim[i]=((r1-a)*10)+(c1-b);
        ++i;
        a++ ;
        b++ ;
    }

}

void pawnb( int r1 , int c1 ) // paido black
{
    pbstatus[c1]++;
    
    
    int i;
	
	
	for (i=0;i<100;++i){
		lim[i]=0;
	}
	
	i=0;
	

    printf( "Available are: \n" ) ;


    if( pbstatus[c1] == 1 )
    {
        if( board[r1-1][c1] == ' ' ){
        	printf( "%d%d , " , r1-1 , c1 ) ;
			lim[i]=((r1-1)*10)+c1;
        	++i;
		}
        if( board[r1-2][c1] == ' ' ){
        	printf( "%d%d , " , r1-2 , c1 ) ;
        	lim[i]=((r1-2)*10)+c1;
        	++i;
    	}
    	
    }
    else
    {
        if(board[r1-1][c1] == ' ' ){
        	printf( "%d%d , " , r1-1 , c1 ) ;
        	lim[i]=((r1-1)*10)+c1;
        	++i;
		}
        if( check2(r1-1 , c1-1) == 1 ){
        	printf( "%d%d* , " , r1-1 , c1-1 ) ;
			lim[i]=((r1-1)*10)+(c1-1);
        	++i;
		}
        if( check2(r1-1 , c1+1) == 1 ){
        	printf( "%d%d* , " , r1-1 , c1+1 ) ;
        	lim[i]=((r1-1)*10)+(c1+1);
        	++i;
    	}
    }

}

void player1()
{
    int p1 , p2 , c1 , r1 , c2 , r2 , i , j;

    printf( "\nPLAYER 1 - Big Case" ) ;
    printf("\tWHITE KILL: %d\tBLACK KILL: %d\n",killw,killb);
    again1:
    printf( "\nEnter Position of Element to change ( RC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;
    
    
    for (i=0 ; i<100 ; ++i) {
    	lim[i]=0;
	}
    

    switch( board[r1][c1] )
    {
        case 'P': pawn( r1 , c1 );
                  break ;
        case 'R': rook( r1 , c1 ) ;
                  break ;
        case 'H': horse( r1 , c1 );
                  break ;
        case 'C': camel( r1 , c1 );
                  break ;
        case 'K': king( r1 , c1 ) ;
                  break ;
        case 'Q': queen( r1 , c1 ) ;
                  break ;
                  
        again3:
        default: printf("Invalid Position ! ") ; goto again1 ;
    }

	again5:
	
    printf( "\nEnter Position of Place to Send ( RC ): " ) ;
    scanf( "%d" , &p2 ) ;
	
	i=0;
	j=0;
	for(i=0; i<100 ;++i){
		if(lim[i]==p2){
			break;
		}
		else {
			++j;
		}	
	}
	
	if(j==100){
		printf("Invalid Position !");
		goto again5;
	}
	
	
	
    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    //change(r1,c1,r2,c2) ;
    
    if (c1==c2 && r1==r2) {
    	goto again3;
	}
	
	if (check2(r2,c2)==1) {
		printf ("You can not commite suicide !!!");
		goto again5;
	} 
    
    
    if (check(r2,c2)==1){
    	
    	board[r2][c2]=' ';
    	++killw;
    	change(r1,c1,r2,c2);
	}
	else {
		change(r1,c1,r2,c2);
	}
    
    
    /*switch( board[r2][c2] )
    {
        case 'p': 
                
        case 'r': 
                  
        case 'h':
                  
        case 'c': 
            
        case 'k': 
                  
        case 'q':
        	
        	board[r2][c2]=' ';
        	change (r1,c1,r2,c2);
        	break;
                  
        default: change (r1,c1,r2,c2) ;
    } h	*/
    
    
    
}

void player2()
{
    int p1 , p2 , c1 , r1 , c2 , r2 , i , j;

    printf( "\nPLAYER 2 - Small Case") ;
    printf("\tWHITE KILL: %d\tBLACK KILL: %d\n",killw,killb);
    again2:
    printf( "\nEnter Position of Element to change ( RC ): " ) ;
    scanf( "%d" , &p1 ) ;

    c1 = p1 % 10 ;
    r1 = p1 / 10 ;
    
    
    for (i=0 ; i<100 ; ++i) {
    	lim[i]=0;
	}
    

    switch( board[r1][c1] )
    {
        case 'p': pawnb( r1 , c1 ) ;
                  break ;
        case 'r': rook( r1 , c1 ) ;
                  break ;
        case 'h': horse( r1 , c1 ) ;
                  break ;
        case 'c': camel( r1 , c1 ) ;
                  break ;
        case 'k': king( r1 , c1 ) ;
                  break ;
        case 'q': queen( r1 , c1 ) ;
                  break ;
                  
        again4:
        default: printf( "Invalid Position ! " ) ; goto again2 ;
    }

	again6:
	
    printf( "\nEnter Position of Place to Send ( RC ): " ) ;
    scanf( "%d" , &p2 ) ;
    
    i=0;
	j=0;
	for(i=0; i<100 ;++i){
		if(lim[i]==p2){
			break;
		}
		else {
			++j;
		}	
	}
	
	if(j==100){
		printf("Invalid Position !");
		goto again6;
	}
    
    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    //change(r1,c1,r2,c2) ;
    
    if (c1==c2 && r1==r2) {
    	goto again4;
	}
    
    
    
    if (check(r2,c2)==1) {
    	printf ("You can not commite suicide !!!");
    	goto again6;
	} 
    
    
    if (check2(r2,c2)==1){
    	
    	board[r2][c2]=' ';
    	++killb;
    	change(r1,c1,r2,c2);
	}
	else {
		change(r1,c1,r2,c2);
	}
    
    
    /*switch( board[r2][c2] )
    {
        case 'P': 
                
        case 'R': 
                  
        case 'H':
                  
        case 'C': 
            
        case 'K': 
                  
        case 'Q':
        	
        	board[r2][c2]=' ';
        	change (r1,c1,r2,c2);
        	break;
                  
        default: change (r1,c1,r2,c2) ;
    }   */  
    
    
    
}

int check(int x , int y )
{
    switch( board[x][y] )
    {
    case 'p':
    case 'r':
    case 'h':
    case 'c':
    case 'k':
    case 'q': return 1 ; break ;
    default: return 0 ;
    }
}

int check2(int x , int y )
{
    switch( board[x][y] )
    {
    case 'P':
    case 'R':
    case 'H':
    case 'C':
    case 'K':
    case 'Q': return 1 ; break ;
    default: return 0 ;
    }
}

int check3(int x , int y)
{
	if (turn%2==0) {
		return check2(x,y);
	}
	else {
		return check(x,y);
	}
}

