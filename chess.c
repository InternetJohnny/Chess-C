#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//CONSTANTES DO SHOWBOARD
#define MAXLINES 10
#define MAXCOL 10
//ESTRUTURAS
typedef struct square
{
	char file;
	char rank;
} SQUARE;

typedef struct pieces
{
	int state;
	int type;
	char color;
	SQUARE square;
} PIECE;
//SHOWBOARD
void showboard(PIECE pieces[32]){
	char piece;
	int i, j;
	int board[MAXLINES][MAXCOL] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, -1,
	    16, 0, 0,0, 0, 0, 0, 0, 0, 16,
	    15, 0, 0, 0, 0, 0, 0, 0, 0, 15,
	    14, 0, 0, 0, 0, 0, 0, 0, 0, 14,
	    13, 0, 0, 0, 0, 0, 0, 0, 0, 13,
	    12, 0, 0, 0, 0, 0, 0, 0, 0, 12,
	    11, 0, 0, 0, 0, 0, 0, 0, 0, 11,
	    10, 0, 0, 0, 0, 0, 0, 0, 0, 10,
	    9, 0, 0, 0, 0, 0, 0, 0, 0, 9,
	    -1, 1, 2, 3, 4, 5, 6, 7, 8, -1
	};
	int pieceIndex =  0;
	int pieceSquare[2];
	for (pieceIndex = 0; pieceIndex < 32; pieceIndex++){
		if(pieces[pieceIndex].state==1){
			pieceSquare[0] = pieces[pieceIndex].square.file - 'a' + 1;
			pieceSquare[1] = '8' - pieces[pieceIndex].square.rank  + 1;
			board[ pieceSquare[1] ][ pieceSquare[0] ] = ( pieces[pieceIndex].color == 'w' ? pieces[pieceIndex].type : -pieces[pieceIndex].type) ;
		}
	}
	    for (i = 0; i < MAXLINES; i++) {
	        printf("\n");
	        for (j = 0; j < MAXCOL; j++) {
	            switch (board[i][j]) {
	                case -1:
	                    piece = ' ';
	                    break;
	                case 0:
	                    piece = ' ';
	                    break;
	                case 1:
	                    piece = 'a';
	                    break;
	                case 2:
	                    piece = 'b';
	                    break;
	                case 3:
	                    piece = 'c';
	                    break;
	                case 4:
	                    piece = 'd';
	                    break;
	                case 5:
	                    piece = 'e';
	                    break;
	                case 6:
	                    piece = 'f';
	                    break;
	                case 7:
	                    piece = 'g';
	                    break;
	                case 8:
	                    piece = 'h';
	                    break;
	                case 9:
	                    piece = '1';
	                    break;
	                case 10:
	                    piece = '2';
	                    break;
	                case 11:
	                    piece = '3';
	                    break;
	                case 12:
	                    piece = '4';
	                    break;
	                case 13:
	                    piece = '5';
	                    break;
	                case 14:
	                    piece = '6';
	                    break;
	                case 15:
	                    piece = '7';
	                    break;
	                case 16:
	                    piece = '8';
	                    break;
	                case 100:
	                    piece = 'P';
	                    break;
	                case 300:
	                    piece = 'N';
	                    break;
	                case 305:
	                    piece = 'B';
	                    break;
	                case 500:
	                    piece = 'R';
	                    break;
	                case 900:
	                    piece = 'Q';
	                    break;
	                case 2000:
	                    piece = 'K';
	                    break;
	                case -100:
	                    piece = 'p';
	                    break;
	                case -300:
	                    piece = 'n';
	                    break;
	                case -305:
	                    piece = 'b';
	                    break;
	                case -500:
	                    piece = 'r';
	                    break;
	                case -900:
	                    piece = 'q';
	                    break;
	                case -2000:
	                    piece = 'k';
	                    break;
	            }
	            if ((i != 0 && j != 0) && (i != MAXLINES - 1 && j != MAXCOL - 1)) {
	                if (((j % 2 != 0 && i % 2 != 0) || (i % 2 == 0 && j % 2 == 0)))
	                    printf("%c[%d;%dm %c %c[%dm", 27, (piece<'a')?36:35, 47, piece, 27, 0); //branco
	                else
	                    printf("%c[%d;%dm %c %c[%dm", 27, (piece<'a')?36:35, 40, piece, 27, 0); //preto
	            } else printf("%c[%d;%dm %c %c[%dm", 27, 37, 44, piece, 27, 0); // branco

	        }
	    }
	    printf("\n\n");
}
//FUNCOES DO MENU
char new_game (PIECE pieces[32])
{
	char jogada = 'w';
	int i;
	FILE *fp;
	fp = fopen("StartGame", "r");
	if (fp==NULL)
	{
		puts("Ficheiro \"Startgame\" nao se encontra na directoria");
	}
	else
		for( i=0 ; i<32 ; i++) 
			fscanf(fp,"%c;%c;%d;%d;%c/\n", &pieces[i].square.file, &pieces[i].square.rank, &pieces[i].state, &pieces[i].type, &pieces[i].color);
	fclose(fp);
	return jogada;
}

char load_game (PIECE pieces[32])
{
	char jogada='a';
	char s[50];
	int i;
	puts("Escolha o nome do ficheiro a carregar:");
	gets(s);
	FILE *fp;
	fp = fopen(s, "r");
	if (fp==NULL)
	{
		puts("Ficheiro Invalido");
	}
	else
	{
		for( i=0 ; i<32 ; i++) 
			fscanf(fp, "%c;%c;%d;%d;%c/\n", &pieces[i].square.file, &pieces[i].square.rank, &pieces[i].state, &pieces[i].type, &pieces[i].color);
		fscanf(fp, "%c", &jogada);
		fclose(fp);
	}
	return jogada;
}

void save_game (PIECE pieces[32], char jogada)
{
	char s[50];
	int i;
	puts("Escolha o nome do ficheiro a salvar:");
	gets(s);
	FILE *fp;
	fp = fopen(s, "w");
	for( i=0 ; i<32 ; i++) 
		fprintf(fp, "%c;%c;%d;%d;%c/\n", pieces[i].square.file, pieces[i].square.rank, pieces[i].state, pieces[i].type, pieces[i].color);
	fprintf(fp, "%c", jogada);
	fclose(fp);
}
//MENU
char menu (PIECE pieces[32], char jogada)
{
	char turn;
	char opcao;
	do
	{
		puts("\n\nJogo de Xadrez\n0 - Sair\n1 - Novo Jogo\n2 - Carregar Jogo\n3 - Salvar Jogo\n4 - Continuar Jogo");
		scanf(" %c", &opcao);
		getchar();
		switch(opcao)
		{
			case '0': exit(1);
			case '1': turn = new_game (pieces); break;
			case '2': turn = load_game (pieces);
					  if(turn=='a')
					 	  opcao = '5';
					  break;
			case '3': save_game (pieces, jogada); break;
			case '4': break;
			default : opcao = '5';
		}
	}
	while(opcao=='5');
	return turn;
}	
//CONDICOES DO JOGO
int verifica_origem_valida (PIECE pieces[32], char coluna_o, char linha_o, char jogada)
{
	int i;
	for (i=0 ; i<32 ; i++)
	{
		if ((pieces[i].square.file==coluna_o) && (pieces[i].square.rank==linha_o) && (pieces[i].state==1) && (pieces[i].color==jogada))
			return i;
	}
	return i;
}

int verifica_destino_valido (PIECE pieces[32], char coluna_d, char linha_d, char jogada, int posicao_peca)
{
	int i, posicao_vitima = 34;
	{
		for (i=0 ; i<32 ; i++)
		{
			if ((pieces[i].square.file==coluna_d) && (pieces[i].square.rank==linha_d) && (pieces[i].state==1))
			{
				if (pieces[i].color==jogada)
					posicao_vitima = 33;
				else
					posicao_vitima = i;
			}
		}
		if (posicao_vitima==34)
			posicao_vitima = 32;
	}
	switch(posicao_vitima)
	{
		case 34 : --posicao_vitima;
		case 33 : break;
		case 32 : pieces[posicao_peca].square.file = coluna_d;
			      pieces[posicao_peca].square.rank = linha_d;
			      break;
		default : pieces[posicao_peca].square.file = coluna_d;
			      pieces[posicao_peca].square.rank = linha_d;
			      pieces[posicao_vitima].state = 0;
			      break;
	}
	return posicao_vitima;
}
//CONDICOES DE MOVIMENTO DAS PECAS
int knight (char coluna_o, char linha_o, char coluna_d, char linha_d)
{
	if ( (((coluna_d==coluna_o+2) || (coluna_d==coluna_o-2)) && ((linha_d==linha_o+1) || (linha_d==linha_o-1))) ||
			(((coluna_d==coluna_o+1) || (coluna_d==coluna_o-1)) && ((linha_d==linha_o+2) || (linha_d==linha_o-2))) )
		return 1;
	return 0;
}

int king (char coluna_o, char linha_o, char coluna_d, char linha_d)
{
	if (((coluna_d==coluna_o-1) || (coluna_d==coluna_o) || (coluna_d==coluna_o+1)) && ((linha_d==linha_o-1) || (linha_d==linha_o) || (linha_d==linha_o+1)))
		return 1;
	return 0;
}

int bishop (PIECE pieces[32], char coluna_o, char linha_o, char coluna_d, char linha_d)
{
	int i, test = 1, comparador_l = -1, comparador_c = -1;
	char coluna, linha;
	if ((coluna_d-coluna_o==linha_d-linha_o) || (coluna_d-coluna_o==-(linha_d-linha_o)) && (coluna_d!=coluna_o) && (linha_d!=linha_o))
	{
		if (linha_d>linha_o)
			comparador_c = 1;
		if (coluna_d>coluna_o)
			comparador_l = 1;
		for (i=0; i<32; i++)
			for (linha = linha_o+comparador_c, coluna = coluna_o+comparador_l; linha!=linha_d; linha+=comparador_c, coluna+=comparador_l)
				if ((pieces[i].square.file==coluna) && (pieces[i].square.rank==linha) && (pieces[i].state==1))
					test = 0;
	}
		else
			test = 0;
	return test;
}

int rook (PIECE pieces[32], char coluna_o, char linha_o, char coluna_d, char linha_d)
{
	int i, test = 1, comparador = -1;
	char coluna, linha;
	if ((coluna_d==coluna_o) && (linha_d!=linha_o))
	{
		if (linha_d>linha_o)
			comparador = 1;
		for (i=0; i<32; i++)
			for (linha = linha_o+comparador; linha!=linha_d; linha+=comparador)
				if ((pieces[i].square.file==coluna_d) && (pieces[i].square.rank==linha) && (pieces[i].state==1))
					test = 0;
	}
	else
		if ((coluna_d!=coluna_o) && (linha_d==linha_o))
		{
			if (coluna_d>coluna_o)
				comparador = 1;
			for (i=0; i<32; i++)
				for (coluna = coluna_o+comparador; coluna!=coluna_d; coluna+=comparador)
					if ((pieces[i].square.file==coluna) && (pieces[i].square.rank==linha_d) && (pieces[i].state==1))
						test = 0;
		}
		else
			test = 0;
	return test;
}

int queen (PIECE pieces[32], char coluna_o, char linha_o, char coluna_d, char linha_d)
{
	if (bishop (pieces, coluna_o, linha_o, coluna_d, linha_d))
		return 1;
	else
		return (rook (pieces, coluna_o, linha_o, coluna_d, linha_d));
}

int pawn (PIECE pieces[32], char coluna_o, char linha_o, char coluna_d, char linha_d, char jogada)
{
	int i, test = 1, plus = 1;
	char j = '2';
	if (jogada=='b')
	{
		plus = -1;
		j = '7';
	}
	if ((coluna_d==coluna_o) && (linha_d==linha_o+2*plus) && (linha_o==j))
	{
		for (i=0 ; i<32 ; i++)
		{
			if ((pieces[i].square.file==coluna_d) && (pieces[i].square.rank==linha_d) && (pieces[i].state==1))
				test = 0;
			if ((pieces[i].square.file==coluna_d) && (pieces[i].square.rank==linha_o+plus) && (pieces[i].state==1))
				test = 0;
		}
	}
	else
	{
		if ((coluna_d==coluna_o) && (linha_d==linha_o+plus))
		{
			for (i=0 ; i<32 ; i++)
				if ((pieces[i].square.file==coluna_d) && (pieces[i].square.rank==linha_d) && (pieces[i].state==1))
					test = 0;
		}
		else
		{
			if (((coluna_d==coluna_o+1) || (coluna_d==coluna_o-1)) && (linha_d==linha_o+plus))
				for (i=0 ; i<32 ; i++)
				{
					if ((pieces[i].square.file==coluna_d) && (pieces[i].square.rank==linha_d) && (pieces[i].state==1))
					{
						test = 1;
						break;
					}
					else
						test = 0;
				}
			else
				test = 0;
		}
	}
	return test;
}
//XEQUE
char xeque (PIECE pieces[32], char jogada)
{
	int i, tipo, comparador, test, n = 0, posicao_vitima = 34;
	char coluna_o, linha_o, col_rei, ln_rei, n_play, play = jogada;
	char jogador[10];
	if (play=='w')
	{
		n_play = 'b';
		strcpy (jogador, "Branco");
}
	else
	{
		n_play = 'w';
		strcpy (jogador, "Preto");
	}
	do
	{
		if (n==1)
		{
			if (play=='w')
			{
				play = 'b';
				n_play = 'w';
				strcpy (jogador, "Preto");
			}
			else
			{
				play = 'w';
				n_play = 'b';
				strcpy (jogador, "Branco");
			}
		}
		for (i=0; i<32; i++)
			if ((pieces[i].type==2000) && (pieces[i].color==play))
			{
				col_rei = pieces[i].square.file;
				ln_rei = pieces[i].square.rank;
			}
		test = 1;
		comparador = test;
		for (i=0; i<32; i++)
		{
			if ((pieces[i].state==1) && (pieces[i].color!=play))
			{
				coluna_o = pieces[i].square.file;
				linha_o = pieces[i].square.rank;
				tipo = pieces[i].type;
				switch (tipo)
				{
					case 100 : test-= pawn (pieces, coluna_o, linha_o, col_rei, ln_rei, n_play);
							   break;
					case 300 : test-= knight (coluna_o, linha_o, col_rei, ln_rei);
							   break;
					case 305 : test-= bishop (pieces, coluna_o, linha_o, col_rei, ln_rei);
							   break;
					case 500 : test-= rook (pieces, coluna_o, linha_o, col_rei, ln_rei);
							   break;
					case 900 : test-= queen (pieces, coluna_o, linha_o, col_rei, ln_rei);
							   break;
					case 2000: test-= king (coluna_o, linha_o, col_rei, ln_rei);
							   break;
				}
			}
		}
		n++;
		if (comparador>test)
			printf(" Xeque %s\n", jogador);
	}
	while(n<2);
	return play;
}
//THE END
void the_end (PIECE pieces[32], char jogada)
{
	char winner[10];
	int i, end = 0;
	for (i=0; i<32; i++)
	{
		if ((pieces[i].type==2000) && (pieces[i].state==0) && (pieces[i].color==jogada))
		{
			end = 1;
			if (jogada=='w')
				strcpy (winner, "BLACK");
			else
				strcpy (winner, "WHITE");
		}
		else
			if ((pieces[i].type==2000) && (pieces[i].state==0) && (pieces[i].color!=jogada))
			{
				end = 1;
				if (jogada=='b')
					strcpy (winner, "BLACK");
				else
					strcpy (winner, "WHITE");
			}
		if (end==1)
		{
			showboard (pieces);
			printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n XXXXXXXXXXXX GAME OVER XXXXXXXXXXXX\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
			printf(" XXXXXXXXXXX %s WINS! XXXXXXXXXXX\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", winner);
			menu (pieces, jogada);
		}
	}
}
//JOGADA
char game (PIECE pieces[32], char jogada)
{
	char coluna_o, linha_o, coluna_d, linha_d, trash;
	char jogador[10];
	int tipo, posicao_peca, test;
	showboard(pieces);
	do
	{
		if (jogada=='w')
			strcpy(jogador, "branco");
		else
			strcpy(jogador, "preto");
		printf(" Jogador %s escolha a posicao origem destino no formato File,Rank ou s para sair\nOrigem:", jogador);
		scanf(" %c,", &coluna_o);
		if (coluna_o=='s' || coluna_o=='S')
		{
			fflush(stdin);
			menu (pieces, jogada);
			showboard (pieces);
			continue;
		}
		scanf(" %c", &linha_o);
		while(trash!='\n')
		{
		scanf("%c", &trash);
		}
		if ((coluna_o<'A' || (coluna_o>'H' && coluna_o<'a') || coluna_o>'h' || linha_o<'1' || linha_o>'8') && (coluna_o!='s' || coluna_o!='S'))
			continue;
		posicao_peca = verifica_origem_valida (pieces, coluna_o, linha_o, jogada);	
		if (posicao_peca==32)
			continue;
		printf("Peca seleccionada : ");
		tipo = pieces[posicao_peca].type;
			switch (tipo)
			{
				case 100 : printf("PAWN"); break;
				case 300 : printf("KNIGHT"); break;
				case 305 : printf("BISHOP"); break;
				case 500 : printf("ROOK"); break;
				case 900 : printf("QUEEN"); break;
				case 2000: printf("KING"); break;
			}
		printf("\nDestino:");
		scanf(" %c", &coluna_d);
		if (coluna_d=='s' || coluna_d=='S')
		{
			menu (pieces, jogada);
			showboard (pieces);
			continue;
		}
		scanf(" %c", &linha_d);
		if ((coluna_d<'A' || (coluna_d>'H' && coluna_d<'a') || coluna_d>'h' || linha_d<'1' || linha_d>'8') && (coluna_d!='s' || coluna_d!='S'))
			continue;
		else
			switch (tipo)
			{
				case 100 : test = pawn (pieces, coluna_o, linha_o, coluna_d, linha_d, jogada);
						   break;
				case 300 : test = knight (coluna_o, linha_o, coluna_d, linha_d);
						   break;
				case 305 : test = bishop (pieces, coluna_o, linha_o, coluna_d, linha_d);
						   break;
				case 500 : test = rook (pieces, coluna_o, linha_o, coluna_d, linha_d);
						   break;
				case 900 : test = queen (pieces, coluna_o, linha_o, coluna_d, linha_d);
						   break;
				case 2000: test = king (coluna_o, linha_o, coluna_d, linha_d);
						   break;
			}
		if (test)
		{
			if (verifica_destino_valido (pieces, coluna_d, linha_d, jogada, posicao_peca)==33)
				continue;
		}
		else
			continue;
		jogada = xeque (pieces, jogada);
		the_end (pieces, jogada);
		showboard(pieces);
	}
	while (1);
}
//PROGRAMA
main()
{
	char jogada;
	PIECE pieces[32];
	jogada = menu(pieces, jogada);
	game(pieces, jogada);
}
