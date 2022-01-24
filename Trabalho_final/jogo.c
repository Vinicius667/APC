#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
 
#define True 1
#define False 0
 
/*Structs*/
 
/*tipo de variavel que guardara as informacoes do personagem*/
typedef struct {
   char nome[25];
   char raca;
   char ali;
   char prof;
   char meta;
   char meio;
   char hist[400];
   char porte;
} pers;
 
/*tipo de variavel que armazena as informacoes de uma charada*/
typedef struct {
   char text[400];
   char certa;
   char alt1[30];
   char alt2[30];
   char alt3[30];
}chara ;
 
/*Variaveis globais*/
 
/* variavel global onde serao guardadas as caracteristicas do personagem */
pers jogador;
 
/*Variavel global onde é armazenada a vida do personagem*/
int vida = 100;
 
 
/*Funcoes*/
 
/*Recebe um char do usuario e faz o tratamento dessa entrada*/
char getinfo(void);
/*Cria jogador caso ainda nao tenha sido criado */
void createjog(void);
/*Subjogos*/
int descubraonum();
void charada();
/*Mostra a vida com uma barra em ascii art*/
void printlife();
/*Mais algumas ascii arts*/
void ascii(int n);
/*Guarda as charadas e faz os controles de nao repeticao*/
void charada();
int displaychar(chara c);
 
 
 
 
 
int main()
{   /*Codigo usado para gerar numeros pseudoaleatorios*/
   srand(time(NULL));
 
   /*guarda as decisoes feitas pelo usuario na main*/
   char decisaomenu;
   char decisao1;
	char decisao2;
	char decisao3;
   char arma[20];
   char continuar;
   char continuar2;
 
 
   /*guarda informacao se ha um personagem criado*/
   char temjog= '0';
 
 
   system("clear");
 
   ascii(-1);
 
   while(True){
 
   printf("Bem vindo ao Jogo!\n\n");
   menujog:
   printf("\n\n");
   if(temjog == '1'){
       	printf("Edite seu personagem ou inicie o jogo!\n");}
   else{
   	printf("Crie um personagem para poder iniciar o jogo!\n");}

   	vida = 100;
 
 
 
   maincriapers:
   printf("1. Criar Personagem\n2. Iniciar jogo\n3. Sair\n");
 
   decisaomenu = getinfo();
 
   if(decisaomenu == '1'){
   	if(temjog == '1'){
       	createjog();
       	}
   	else{
       	temjog = '1';
       	createjog();}}
 
	else if(decisaomenu=='2'){
   	if(temjog != '1'){
       	printf("Voce ainda nao possui um personagem!\n\n");
       	goto maincriapers;
   	}
	}
 
 
	else if(decisaomenu == '3'){break;}
 
	else{
       	printf("Comando Invalido!\n");
       	goto menujog;}
 system("clear");
   printf("\n\nBem vindo a Darkland, um mundo fantastico de aventuras e desafios!\n");
   printf("Cuidado com suas decisoes. Seu futuro e o resultado da sua jornada depende delas!\n");
   printf("Mostre sua bravura, venca desafios, conquiste Darkland!\n\n");
 
   printf("Um rei tirano, Felix Magnus, controla Darkland com mao de ferro e destroi todos aqueles que se oponhem a ele.\n");
   printf("O rei nao tem apoiadores, mas possui criaturas magicas que o protege suprimindo qualquer tipo de revolta!\n");
   printf("A ultima acao do rei Magnus deixou todos infurecidos. A partir de hoje, todos aqueles que desajarem sairem\nde Darkland, deverao ter a aprovacao do rei!\n");
 
   printf("Voce, assim como varios outras pessoas, resolve agir.\nMas para isso, voce deve decidir,%s:\n",jogador.nome);
   ascii(5);
   maindec1:
   printf("Qual sera sua arma de combate?\n");
   printf("\n1 - Lanca magica.\n");
   printf("2 - Adaga encantada.\n");
   printf("3 - Espada enfeiticada.\n");
 
   decisao1 = getinfo();
 
   if(decisao1 !='1' && decisao1 !='2' && decisao1 !='3'){
   	printf("Comando Invalido!\n\n");
   	goto maindec1;
   }
 
 
   switch(decisao1){
   	case '1':
       	strcpy(arma,"lanca magica");
       	break;
   	case '2':
       	strcpy(arma,"adaga encantada");
       	break;
   	case '3':
       	strcpy(arma,"espada enfeiticada");
       	break;
 
   	default:
       	break;
 
   }
   system("clear");
   printf("Por sorte, Hefesto, melhor ferreiro de Darkland eh um grande amigo seu!\n");
   printf("Hefesto produziu sua %s. Essa sera sua melhor companheira daqui \npara frente! ",arma);
 
   printf("Em Darkland, varias pessoas decidiram tentar destronar o rei Magnus.\n");
   printf("Dentre eles, se destacam os Bloodters e os Clipters, grupos que concordam em\n");
   printf("nada a nao ser em quererem acabar com o governo tirano de Magnus.\n");
   printf("Os Bloodters clamam que deve ocorrer uma revolucao pelo uso da forca ou qualquer\n");
   printf("meio necessario. Enquanto os Clipters pensam que deve ocorrer uma mudanca lenta, gradual e democratica.\n");
   ascii(5);
   printf("A caminho do castelo do rei, voce encontra esses dois grupos. O que deseja fazer?\n\n");
 
   maingroup:
   if(jogador.ali == '1'){
   printf("1 - Juntar-se aos Bloodters.\n");
   printf("2 - Juntar-se aos Clipters. -- opcao exlcuida\n" );
   printf("3 - Nao se juntar a nenhum deles.\n");}
 
   if(jogador.ali == '3'){
   printf("1 - Juntar-se aos Bloodters. -- opcao exlcuida\n");
   printf("2 - Juntar-se aos Clipters. \n" );
   printf("3 - Nao se juntar a nenhum. deles.\n");}
 
   if(jogador.ali == '2'){
   printf("1 - Juntar-se aos Bloodters.\n");
   printf("2 - Juntar-se aos Clipters. \n" );
   printf("3 - Nao se juntar a nenhum deles. -- opcao exlcuida\n");}
 
   maindec2:
   decisao2 = getinfo();
 
   if((jogador.ali == '1') && (decisao2 == '2')){
   	printf("Os Clipters nunca deixariam alguem perverso como voce juntar-se a eles\n");
   	printf("Escolha outra opcao.\n");
   	goto maindec2;
   }
 
   if((jogador.ali == '3') && (decisao2 == '1')){
   	printf("Os Bloodters nunca deixariam alguem bonzinho como voce juntar-se a eles\n");
   	printf("Escolha outra opcao.\n");
   	goto maindec2;
   }
 
   if((jogador.ali == '2') && (decisao2 == '3')){
   	printf("Ficar entre dois grupos raivosos não parece ser uma boa opção para voce.\n");
   	printf("Escolha outra opcao.\n");
   	goto maindec2;
   }
 
  system("clear");
 
   if(decisao2 == '1'){
   	printf("Voce e os Bloodters marcham para o castelo real.\n");
   	printf("Os guardas ao perceberem a movimentacao, deslocam suas\n");
   	printf("tropas para frente do castelo e o combate comeca!");
   	printf("Voce se ve ali em meio aquela confusao e pensa se juntar-se\n");
   	printf("aos Bloodters foi realmente uma boa opcao.");
   	printf("O que deseja fazer, jogador?\n\n");
   }
 
   if(decisao2 == '2'){
   	printf("Voce e os Clipters marcham para o castelo real.\n");
   	printf("Os guardas ao perceberem a movimentacao, deslocam suas\n");
   	printf("tropas para frente do castelo e o combate comeca!\n");
   	printf("Apesar de pacificos, os Clipters nao fojem do combate\n");
  	printf("Voce se ve ali em meio aquela confusao e pensa se juntar-se\n");
   	printf("e eles foi realmente uma boa opcao.");
   	printf("O que deseja fazer, jogador?\n\n");
   }
 
   	if(decisao2 == '3'){
   	printf("Voce entao se desloca solitariamente para o castelo real\n");
   	printf("Chegando la, percebe muitos guardas vigiando o Castelo e pensa se\n");
   	printf("nao ter se juntado a algum grupo nao foi uma ma ideia. Talvez um pouco\n");
   	printf("de distracao poderia ajudar\n");
   	printf("O que deseja fazer, jogador?\n\n");
   }
 
 
   printf("1 - Voltar a decisao anterior\n");
   printf("2 - Usar uma roupa de guarda real e infiltrar-se no castelo\n");
   switch(jogador.prof){
   case '1':
   	printf("3 - Enfrentar todos eles com sua poderosa %s\n",arma);
   	break;
   case '2':
   	printf("3 - Usar sua magia para passar despercibido pelos guardas\n");
   	break;
   case '3':
   	printf("3 - Subornar seu amigo guarda real para deixa-lo entrar\n");
   }
   decisao3 = getinfo();
   if(decisao3=='1'){
       	goto maingroup;}

  system("clear");
 
  printf("\nOtima escolha, %s. Voce conseguiu entrar no castelo de Magnus.\n",jogador.nome);
  printf("Apenas um problema, voce esta sozinho e uma criatura medonha logo percebe sua presenca.\n");
  printf("Seu nome eh Xiong, uma criatura que soh eh possivel de derrotar respondendo 3 charadas ditas impossiveis.\n");
  printf("A cada pergunta errada, Xiong te golpeia com suas garras afiadas causando um dano de 10 pontos de vida!\n");
  printf("Entao tenha muito cuidado a responder suas charadas\n");
  printf("Tente derrota-lo!!\n\n\n");
 
 
   charada(); 
   if(vida <=0){
   ascii(0);
   perdeucontinua:
   printf("\nDeseja jogar novamente?\n");
   printf("1 Sim\n2 Nao\n");
    fflush(stdin);
   continuar = getinfo();
   if(continuar != '1' && continuar != '2'){
   	printf("Comando invalido.\n");
   	goto perdeucontinua;}
   if(continuar=='1'){
   	system("clear");
   	goto menujog;
   }
   else{break;}
   goto menujog;
   }
  system("clear");
   ascii(2);
   sleep(2);
   printf("Voce acertou a ultima questao de Xiong, ele uiva de raiva pela sua vitoria e\n");
   printf("te mostra suas garras afiadas em forma de ameaça, mas voce não tem\n");
   printf("piedadade para monstros enfia sua %s no peito dele o matando.\n\n",arma);
   printf("Voce sobe todas as escadas do castelo, e entra no salao real.\n");
   printf("No final do salao, voce enxerga Magnus sentado no seu trono, mas para chegar\n");
   printf("ate ele voce tem que passar por Numermort, um dragao magico que cospe fogo cada vez que\n");
   printf( "voce erra o numero pensado por ele causando um dano de 10 pontos de vida, entao cuidado.\n");
   printf("Para vence-lo voce deve passar pelo seu desafio\n\n");
   printf("O numero pensando por Numermort tem 4 digtos que nao se repetem\n");
   descubraonum();
   if(vida>0){
  	system("clear");
  	ascii(3);
  	sleep(2);
   	printf("Bravo, nobre jogador! Voce conseguiu derrotar, Numermort!\n");
   	printf("Voce o deixa voar para longe, afinal ele estava sendo aprisionado por Magnus.\n");
   	printf("Finalmente, apenas voce e Magnus no salao real, ele olha assustado enquanto voce o encara.\n");
   	printf("Voce finalmente conseguiu destronar Magnus.\n");
 
   }
 
   else{
 
    	ascii(0);
    	perdeucontinua2:
    	printf("\nDeseja jogar novamente?\n");
    	printf("1 Sim\n2 Nao\n");
      fflush(stdin);
    	continuar = getinfo();
    	if(continuar != '1' && continuar != '2'){
        	printf("Comando invalido.\n");
        	goto perdeucontinua2;}
    	if(continuar=='1'){
       	system("clear");
        	goto menujog;
    	}
    	else{break;}
    	goto menujog;
   }
 
 
   switch(jogador.meta){
   case '1':
   	printf("O reino eh finalmente eh seu como voce queria desde o inicio.\n");
   	break;
   case '2':
   	printf("Agora toda a riqueza do reino eh sua e dinheiro nao eh mais um probloma\nque eh seu objetivo desde o inicio\n");
   	break;
   case '3':
   	printf("Finalmente o mal em Darkland foi derrotado, assim a paz reinará novamente sem mais um rei tirano.\n");
   	break;
   }
 
 
 
   switch(jogador.ali){
   
   case '1':
   	printf("Quanto a Magnus, voce deixou ele para que os Bloodters vingassem toda sua raiva por meio dos piores tipos de tortura possiveis.\n");
   	break;
   case '2':
   	printf("Quanto a Magnus, voce achou melhor deixar que o povo de Darkland decidisse o seu destino e acredite, esse nao vai ser nada glorioso.\n");
   	break;
   case '3':
   	printf("Quanto a Magnus, voce achou melhor leva-lo a julgamento, onde foi sentenciado a passar varios anos por tras das grades.\n");
   	break;
   }
 
 
   printf("\nParabens, %s !!\n\n\n",jogador.nome);
    	ascii(1);
    	ganhoucontinua:
    	printf("\nDeseja jogar novamente?\n");
    	printf("1 Sim\n2 Nao\n");
      fflush(stdin);
    	continuar2 = getinfo();
    	if(continuar2 != '1' && continuar2 != '2'){
        	printf("Comando invalido.\n");
        	goto ganhoucontinua;}
    	if(continuar2=='1'){
        	goto menujog;
    	}
    	else{break;}
   }
 
 
   return 0;
}
 
char getinfo(void){
   char i[100];
   recebe:
   fgets(i,100, stdin);
   if(i[0]=='\n'){
    goto recebe;}
   if(strlen(i)>2 || (i[0] !='1' && i[0] !='2' && i[0] !='3') ){
   	printf("Comando Invalido! Escolha uma opcao valida\n");
   	goto recebe;
   	return 'z';
   }
   else{
   	return i[0];
   }
 
 
}
 
/*cria personagem*/
void createjog(void){
	system("clear");
 
	int tam;
   printf("Nome do personagem: ");
   fgets(jogador.nome,21,stdin);
   tam = strlen(jogador.nome);
   jogador.nome[tam-1] = '\0';
 
   createjograca:
   system("clear");
   printf("Raca\n1 - Humano \n2 - Anao \n3 - Elfo\n");
   jogador.raca = getinfo();
 
   if(jogador.raca !='1' && jogador.raca !='2' &&jogador.raca !='3'){
   	printf("Comando Invalido!\n\n");
   	goto createjograca;
   }
 
   createjogali:
   system("clear");
   printf("Alinhamento do personagem \n1 - Mal \n2 - Neutro  \n3 - Bom\n");
   jogador.ali = getinfo();
   if(jogador.ali !='1' && jogador.ali !='2' &&jogador.ali !='3'){
   	printf("Comando Invalido!\n");
   	goto createjogali;
   }
 

   system("clear");
   createjogprof:
   printf("Classe \n1 - Guerreiro \n2 - Mago \n3 - Ladino\n");
   jogador.prof = getinfo();
   if(jogador.ali == '3' && jogador.prof == '3'){
   	printf("Um ladino do bem? Voce esta de brincadeira! Escolha outra classe!\n");
   	goto createjogprof;
   }
   else if(jogador.prof !='1' && jogador.prof !='2' &&jogador.prof !='3'){
   	printf("Comando Invalido!\n");
   	goto createjogprof;
   }
    
   system("clear");
   createjogmeta:
   printf("Meta \n1 - Governar o reino \n2 - Ficar rico \n3 - Destruir o Mal\n");
   jogador.meta = getinfo();
   if(jogador.ali == '1' && jogador.meta == '3'){
   	printf("O mal esta no seu sangue. Mudar agora nao eh uma escolha! Escolha outra meta!\n");
   	goto createjogmeta;
   }
   else if(jogador.meta !='1' && jogador.meta !='2' &&jogador.meta !='3'){
   	printf("Comando Invalido!\n");
   	goto createjogmeta;
   }
 
  system("clear");
   createjogmeio:
   printf("Meio em que vive \n1 - Urbano \n2 - Rural \n3 - Tribal\n");
   jogador.meio = getinfo();
   if(jogador.prof == '3' && jogador.meio == '3'){
   	printf("Um ladino em uma tribo eh como abrigar um lobo num galinheiro.Escolha outro meio!\n");
   	goto createjogmeio;
   }
   else if(jogador.meio !='1' && jogador.meio !='2' &&jogador.meio !='3'){
   	printf("Comando Invalido!\n");
   	goto createjogmeio;
   }
  system("clear");
   printf("Conte um pouco da sua historia, %s\n",jogador.nome);
   fgets(jogador.hist,400, stdin);

   system("clear");
   createjogporte:
   printf("Porte \n1 - Grande \n2 - Medio \n3 - Pequeno\n");
   jogador.porte = getinfo();
   if(jogador.raca == '2' && jogador.porte == '1'){
   	printf("Um anao grande? Leve o jogo a serio por favor! Escolha outro porte!\n");
   	goto createjogporte;
   }
   else if(jogador.porte !='1' && jogador.porte !='2' &&jogador.porte !='3'){
   	printf("Comando Invalido!\n");
   	goto createjogporte;
   }
 system("clear");
}
 
void printlife(){
   printf("Vida:   ");
   switch(vida){
   case 0:
   	printf("▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁ 0%%\n");
   	break;
   case 10:
   	printf("██▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁ 10%%\n");
   	break;
   case 20:
   	printf("████▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁ 20%%\n");
   	break;
   case 30:
   	printf("██████▁▁▁▁▁▁▁▁▁▁▁▁▁▁ 30%%\n");
   	break;
   case 40:
   	printf("████████▁▁▁▁▁▁▁▁▁▁▁▁ 40%%\n");
   	break;
   case 50:
   	printf("██████████▁▁▁▁▁▁▁▁▁▁ 50%%\n");
   	break;
   	case 60:
   	printf("████████████▁▁▁▁▁▁▁▁ 60%%\n");
   	break;
   case 70:
   	printf("██████████████▁▁▁▁▁▁ 70%%\n");
   	break;
   case 80:
   	printf("████████████████▁▁▁▁ 80%%	\n");
   	break;
   case 90:
   	printf("██████████████████▁▁ 90%%	\n");
   	break;
   case 100:
   	printf("████████████████████ 100%%   \n");
   	break;
   }
printf("\n");
 
}
 
int displaychar(chara c){
   /*resposta do usuario*/
   char k;
 
   printf("%s\n",c.text);
   printf("1 - %s\n",c.alt1);
   printf("2 - %s\n",c.alt2);
   printf("3 - %s\n",c.alt3);
 
 
 
   k = getinfo();
 
   if(k== c.certa){
   	printf("Acertou\n\n");
   	return 1;}
   else{
   	printf("Errou\n");
   	vida -= 10;
   	printlife();
   	return 0;
   }
 
 
   return 0;
}
 
void charada(){
   chara ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11,ch12,ch13,ch14;
 
   strcpy(ch0.text,"Quantos meses possuem 28 dias?");
   strcpy(ch0.alt1,"1");
   strcpy(ch0.alt2,"2");
   strcpy(ch0.alt3,"12");
   ch0.certa = '3';
 
   strcpy(ch1.text,"O que eh, o que eh? Me alimente e eu vivo. Me de agua e eu morro.");
   strcpy(ch1.alt1,"Cobra");
   strcpy(ch1.alt2,"Eletrcidade");
   strcpy(ch1.alt3,"Fogo");
   ch1.certa = '3';
 
   strcpy(ch2.text,"O que quanto mais seca, mais umida fica?");
   strcpy(ch2.alt1,"Antartida");
   strcpy(ch2.alt2,"Toalha");
   strcpy(ch2.alt3,"Sol");
   ch2.certa = '2';
 
   strcpy(ch3.text,"O que eh seu, mas eh mais usado pelos outros?");
   strcpy(ch3.alt1,"Nome");
   strcpy(ch3.alt2,"Umbigo");
   strcpy(ch3.alt3,"Celular");
   ch3.certa = '1';
 
   strcpy(ch4.text,"O que esta sempre na frente de voce, mas nao poder ver?");
   strcpy(ch4.alt1,"O futuro");
   strcpy(ch4.alt2,"O nariz");
   strcpy(ch4.alt3,"O oculos");
   ch4.certa = '1';
 
   strcpy(ch5.text,"O que aumenta, mas nunca diminui?");
   strcpy(ch5.alt1,"Minha paixao pelo flamengo");
   strcpy(ch5.alt2,"A idade");
   strcpy(ch5.alt3,"Preguica");
   ch5.certa = '2';
 
   strcpy(ch6.text,"O que voce pode manter apos dar a alguem?");
   strcpy(ch6.alt1,"Seu dinheiro");
   strcpy(ch6.alt2,"Sua palavra");
   strcpy(ch6.alt3,"Sua senha do Facebook");
   ch6.certa = '2';
 
   strcpy(ch7.text,"Eu nao sou nem um pouco pesado, mas nem o homem mais forte\ndo mundo consegue me segurar por muito tempo O que eu sou?");
   strcpy(ch7.alt1,"Peso");
   strcpy(ch7.alt2,"Sacola de compras");
   strcpy(ch7.alt3,"Respiracao");
   ch7.certa = '3';
 
   strcpy(ch8.text,"O rico precisa disso, o pobre tem isso. Se voce comer isso voce morre.\nOque eu sou?");
   strcpy(ch8.alt1,"Nada");
   strcpy(ch8.alt2,"Dinheiro");
   strcpy(ch8.alt3,"Casa");
   ch8.certa = '1';
 
   strcpy(ch9.text,"O que eh que quando tem mais rugas, mais novo e?");
   strcpy(ch9.alt1,"Idosos");
   strcpy(ch9.alt2,"arvores");
   strcpy(ch9.alt3,"Pneus");
   ch9.certa = '3';
 
   strcpy(ch10.text,"O que eh, o que eh? Anda com os pes na cabeca.");
   strcpy(ch10.alt1,"O contorcionista");
   strcpy(ch10.alt2,"O piolho");
   strcpy(ch10.alt3,"O homem elastico");
   ch10.certa = '2';
 
   strcpy(ch11.text,"O que eh, o que eh? Quando mais se tira, mais se aumenta.");
   strcpy(ch11.alt1,"Divida");
   strcpy(ch11.alt2,"Buraco");
   strcpy(ch11.alt3,"Vida");
   ch11.certa = '2';
 
   strcpy(ch12.text,"O que eh o que e, tem chapeu, mas nao tem cabeca, tem boca mas nao fala, tem asa mas nao voa?");
   strcpy(ch12.alt1,"Chapeleiro");
   strcpy(ch12.alt2,"Jarra");
   strcpy(ch12.alt3,"Bule");
   ch12.certa = '3';
 
   strcpy(ch13.text,"O que eh que da um pulo e se veste de noiva?");
   strcpy(ch13.alt1,"Cigarra");
   strcpy(ch13.alt2,"Pipoca");
   strcpy(ch13.alt3,"Noiva");
   ch13.certa = '2';
 
   strcpy(ch14.text,"O que eh, o que eh? De dia tem quatro pes e de noite tem seis?");
   strcpy(ch14.alt1,"O perneta");
   strcpy(ch14.alt2,"Ben-10");
   strcpy(ch14.alt3,"A cama");
   ch14.certa = '3';
 
 
   int numsort;
   chara riddles[] = {ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11,ch12,ch13,ch14};
   int usadas[15] = {0};
   int cont = 0;
 
   sorteia:
   numsort = rand() %15;
   if(usadas[numsort]==1 && vida >0){
    goto sorteia;}
   usadas[numsort] = 1;
 
   if(displaychar(riddles[numsort])){
    cont++;}
   if(cont<3 && vida >0){
    goto sorteia;}
 
}
 
int descubraonum()
{
   srand(time(NULL));
   /*variaveis de controle de iteracoes*/
   int i,j,k,p =0;
   /*vetor onde vao ser armazenados os numeros*/
   int  vec[4] = {-1,-1,-1,-1};
   char g[100];
   int conta =0;

   descrand:
   k = rand() % 10;
   for(i=0;i<4;i++){
   	if(vec[i] == k){
       	goto descrand;}}
 
   	vec[p] = k;
   	p++;
 
   if(vec[3] == -1){goto descrand;}
 

   getguess:
   printf("Acerte o numero de 4 digitos:\n");
   scanf(" %s",g);
   int tam = strlen(g);
   if(tam != 4){
   	printf("Numero invalido. O numero deve conter 4 digitos de 1 a 9\n");
   	goto getguess;
   }
   for(i=0;i<tam;i++){
   	if(!isdigit(g[i])){
       	printf("Numero invalido. O numero deve conter 4 \ndigitos de 1 a 9\n");
       	goto getguess;
   	}
   }
 
   conta = 0;
   for(i=0;i<4;i++){
   	if((g[i]-48)==vec[i]){
   		conta++;}
   }
 
   int outofplace = 0;
   for(i=0;i<4;i++){
   	for(j=0;j<4;j++){
       	if(((g[i]-48)!=vec[i]) && ((g[i]-48) == vec[j])){
           	outofplace++;
       	}
   }}
 
   printf("%d digitos estao nas posicoes corretas\n",conta);
 
   printf("%d digitos estao no numero mas em posicoes incorretas\n",outofplace);
 
 
 
 
   if(conta ==4){
   	printf("Parabens! Voce acertou!\n\n");
   	goto acaboujogo;
   }
 
   else{vida -=10;
   	printlife();
   	if(vida>0)
       	{goto getguess;}
 
   }
acaboujogo:
printf("\n");
if(vida<=0){
  printf("O numero pensado por Numermort foi %d%d%d%d\n\n\n",vec[0],vec[1],vec[2],vec[3]);
}
return 0;
}
 
 
 
void ascii(int n){
 
	switch(n){
    	case 0:
printf("▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▓█████ \n");
        printf(" ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓█   ▀ \n");
        printf("  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒███   \n");
        printf("  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒▒▓█  ▄ \n");
        printf("  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒░▒████▒\n");
        printf("   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░░ ▒░ ░\n");
        printf(" ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░ ░ ░  ░\n");
        printf(" ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░     ░   \n");
        printf(" ░ ░         ░ ░     ░            ░  ░    ░ ░        ░     ░  ░\n");

    	break;
 
    	case 1:
        printf("▄██   ▄    ▄██████▄  ███    █▄        ▄█     █▄   ▄█  ███▄▄▄▄   \n");
        printf("███   ██▄ ███    ███ ███    ███      ███     ███ ███  ███▀▀▀██▄ \n");
        printf("███▄▄▄███ ███    ███ ███    ███      ███     ███ ███▌ ███   ███ \n");
        printf("▀▀▀▀▀▀███ ███    ███ ███    ███      ███     ███ ███▌ ███   ███ \n");
        printf("▄██   ███ ███    ███ ███    ███      ███     ███ ███▌ ███   ███ \n");
        printf("███   ███ ███    ███ ███    ███      ███     ███ ███  ███   ███ \n");
        printf("███   ███ ███    ███ ███    ███      ███ ▄█▄ ███ ███  ███   ███ \n");
        printf(" ▀█████▀   ▀██████▀  ████████▀        ▀███▀███▀  █▀\n");
    	break;
 
    	case -1:
          printf(" ______   _______  _______  _        _        _______  _        ______  \n");
         printf("(  __  \\ (  ___  )(  ____ )| \\    /\\( \\      (  ___  )( (    /|(  __  \\ \n");
         printf("| (  \\  )| (   ) || (    )||  \\  / /| (      | (   ) ||  \\  ( || (  \\  )\n");
         printf("| |   ) || (___) || (____)||  (_/ / | |      | (___) ||   \\ | || |   ) |\n");
         printf("| |   | ||  ___  ||     __)|   _ (  | |      |  ___  || (\\ \\) || |   | |\n");
         printf("| |   ) || (   ) || (\\ (   |  ( \\ \\ | |      | (   ) || | \\   || |   ) |\n");
         printf("| (__/  )| )   ( || ) \\ \\__|  /  \\ \\| (____/\\| )   ( || )  \\  || (__/  )\n");
         printf("(______/ |/     \\||/   \\__/|_/    \\/(_______/|/     \\||/    )_)(______/ \n\n\n");

        	break;
 
       	case 2:
  printf("              \n");
           printf("           \n");
           printf("                    ..i'             q.\n");
           printf("                 .poj;                \\*.\n");
           printf("      .         oKPO                   THk\n");
           printf("     .k        {HHk`                    THH,\n");
           printf("     dH,       ;YJH.                     YHHk\n");
           printf("    {HHk       :lHHk                     jHHH}\n");
           printf("     THHk      `NJHH,                   .HHHl'\n");
           printf("      THHk,     lHHHHk                 jHHHHP\n");
           printf("       THHHi:,  `GHHHHH,.            .'HHHHH\n");
           printf("        `THHHHHHi\\WHHHHHkoo....ooooojHHHHHHF\n");
           printf("          `*THHHH`THHHHHHHHHHHHHHHHHHHHHHHHl\n");
           printf("             `*THHHYHHHHHHHHHHHHHHHHHHHHHHHI\n");
           printf("                `*THHYHHHHHHHHHHHHHHHHHHHHHH}\n");
           printf("                  `*THHHHHHHHHHHHHHHHHHHHHH}\n");
           printf("                     `THHHHHHHHHHHHHHHHHHHP\n");
           printf("                       `THHHHHHHHHHHHHHHHHH|\n\n\n");
       	break;
 
       	case 3:
           printf("            ,d88\"\n");
           printf("           ,888;\n");
           printf("          ,888;\n");
           printf("          8888\n");
           printf("         :8888\n");
           printf("         `8888\n");
           printf("         `8888\n");
           printf("          Y888.\n");
           printf("         b 888;\n");
           printf("         8.:888.\n");
           printf("         :8.:88b\n");
           printf("         :88.\"88b\n");
           printf("          888.:88b.\n");
           printf("           `Y8;`888\n");
           printf("          :b `8b`888o\n");
           printf("           88o Yb`888b\n");
           printf("           :88b.\"b:8888.\n");
           printf("            `888o\"b88888b\n");
           printf("            , \"88o8d88oY88.     `Y8o.                ,8888bo\n");
           printf("            :8o \"8bY888b:88b      \"888888888888b.    Y8;   Y8.\n");
           printf("             888o`8b8888b`888.     `Y88888888\"d88ooo. \"     88\n");
           printf("             Y888b`8888888`Y88b        88888P:\"Y8888888o    88'\n");
           printf("              `888b`8888888.\"88b     d8888888888P\"\"\"'  `\"  d8;\n");
           printf("              b.`\"8bY8888888o`Y8b.  d888`888888. ooo.  ,oo88\"\n");
           printf("              Y88o.\"888888888b.Y8b :8888:888888bo.`8888888888\n");
           printf("              o`\"Y8bd88888Y8888.Y8od8Y88:88888888bo \"88888`\"'\n");
           printf("              :bo `\"888888'Y8888 Y888.Y8'88888' `\"\"\" `\"88'\n");
           printf("               \"888od888888'8888;`8888.Yb'888\n");
           printf("              :b `\"88888888b`8888 88:88o`Y888\n");
           printf("              :88boo.Y888888.Y888 88;8888o Y8.\n");
           printf("              :8888888888888;:888;88;P:'888o`8.\n");
           printf("              :P ,oooo\"888888:888 88'8d8.`888oY.\n");
           printf("              `d888888888888P:88Pd8Pd8b\"8b.\"88888oo\n");
           printf("             o88888888888888 d8888Pb888o\"88o'\"88P\"88P'\n");
           printf("             88\"\"' ,oo8888P`d888PYo88888b'Y88o'Y8.\n");
           printf("             8`oo8888888888888\"',888888888o'\"88bPYb\n");
           printf("             o88888888888888P'  d88888888888bo\"Y8bPb.\n");
           printf("            :888888\"Yd88888P  ,d888888888888888oPY8db.\n");
           printf("            8888\"',88888888' ,\"'  oooo888888888888.Y88\n");
           printf("           :88P',8888888888;d88888888888888P\"Y88888b:8.\n");
           printf("           88 d888d88888888dY8888888888888888b'8888b:8\n");
           printf("            :;d888;88888888888888888888o'\"888888b`888;8;\n");
           printf("             ,888P:8888888888888888888888b.Y88888b'888:;\n");
           printf("             ,888;8888 88888888888888bd888b`888888bY88:;\n");
           printf("              888;8888 8888888888888888dY88.8888888`88d;\n");
           printf("              Y88.Y888b888888\"  .`Y88888:88;:888888 888'\n");
           printf("              `Y8;:8888:88888   8b 88888888b8888888d888\n");
           printf("              ,d'8.8888.Y888888888 88888888d88888Y;888'\n");
           printf("              888bY Y888.88888888P,8888Pd8888888P8:88'\n");
           printf("             888888o Y8888d88888Yd8888Pd8888888P8`88'\n");
           printf("            d88888888boY888888888888P`88888888Pd'88\"\n");
           printf("           :88P888;8888\"Ybd88\"\"\"P\"\"d888888888\"dPdP'  -hrr-\n");
           printf("           888b888;8888 :8888888;  888Y8888P`8PdP'\n");
           printf("           888:888;8888;d8888888; :88':888Pb8\"dP\n");
           printf("           888:8888`888b888Po888  `8P d88Pd8PdP'\n");
           printf("           888:8888.88888P`o888'   8; 88P88;d8'\n");
           printf("           888;8888b8888'd8888'    `8 8888Pd8'\n");
           printf("           :88;:8888888888888         8888:88\n");
           printf("            Y88.888888d8888P          888;888\n");
           printf("             88;888888888P'           :88b888\n");
           printf("             `88`888888P'             `88;888;\n");
           printf("              Y8 88888\"                Y8b888b\n");
           printf("               Y888888                  Y88888b\n");
           printf("               d888888b.                 Y88888bood8888.\n");
           printf("              :888b88888P88P88b           \"8888888888888\n");
           printf("               :8d888888b888d88             Y8888888888;\n\n\n");
       	break;
 
       	case 4:
        	printf("===========================================================================\n");
        	break;
	}
}
 
 
 



