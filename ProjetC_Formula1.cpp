#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
typedef struct
{   
	char nomEC[20];
	char paysEC[20];
	int  nbpEC=0;
}ecuire;
typedef struct
{
	int id;
	char nomP[20];
	char pernomP[20];
	char pays[20];
	int nbpP=0;
	ecuire ec;
}pilote;
typedef struct
{
	int m;
	int s;
	int ms;
}duree;
typedef struct
{
    char nompp[20];
    char payspp[20];
	duree dr;
}classement;
typedef struct
{
	int num;
	char nomC[30];
	int nbtr;
	char date[20];
	ecuire te[10];
	int nte=0;	
    pilote tp[20];
    int ntp=0;
	classement clas[20];
	int ntc=0;
}grandPrix;
void saisirP(pilote *p)
{
	printf("id=");
	scanf("%d",&p->id);
	printf("nom=");
	scanf("%s",p->nomP);
	printf("prenom=");
	scanf("%s",p->pernomP);
	printf("pays du pilote");
	scanf("%s",p->pays);
}
void saisirEC(ecuire *e)
{
	printf("nom=");
	scanf("%s",e->nomEC);
	printf("pays=");
	scanf("%s",e->paysEC);
}
int rechP(pilote *tp,int np,int id)
{
	int i=0;
	while(id!=tp[i].id && i<np)	
		i++;
	if(i<np)
	return i;
	return -1;
}
int rechEC(ecuire *te,int ne,char* nom)
{
	int i=0;
	while((strcmp(nom,te[i].nomEC)!=0) && (i<ne))	
		i++;
	if(i<ne)
	 return i;
	 return -1;
}
int rechg(grandPrix *tg,int ng,char* nom)
{
	int i=0;
	while((strcmp(nom,tg[i].nomC)!=0) && (i<ng))	
		i++;
	if(i<ng)
	 return i;
	 return -1;
}
int rechE(pilote *tp,int np,char*nomE)
{
	int occ=0;
	for(int i=0;i<np;i++)
	{
		if(strcmp(tp[i].ec.nomEC,nomE)==0)
		 {
		 	occ+=1;
		 }
	}
	return occ;	
}
int rechEP(pilote*tp,int np,char*nom)
{
	int i=0;
	while((strcmp(tp[i].ec.nomEC,nom)!=0) && (i<np))
	
		i++;
	if(i<np)  
	 return i;
	 return -1;
}
void ajoutP(grandPrix *tg,pilote p,int ng,ecuire *e)
{
	char nomE[20];
	if((tg[ng].ntp<20) && (rechP(tg[ng].tp,tg[ng].ntp,p.id)==-1))
	 {
	 	tg[ng].tp[(tg[ng].ntp)++]=p;

	 int n=tg[ng].ntp;
	printf("donner le nom de leur ecuire\n");
	scanf("%s",nomE);
	 int pe= rechEC(tg[ng].te,tg[ng].nte,nomE);
	if(rechE(tg[ng].tp,tg[ng].ntp,nomE)==0 && (pe==-1))
	{
		saisirEC(e);
	    tg[ng].tp[n-1].ec=*e;
	    tg[ng].te[tg[ng].nte]=*e;
	    (tg[ng].nte)++;
		printf("enregister avec suee\n");}
	   else if(rechE(tg[ng].tp,tg[ng].ntp,nomE)==0 && pe!=-1)
	   {
	   	 tg[ng].tp[n-1].ec=tg[ng].te[pe];
		   }	
	   else if(rechE(tg[ng].tp,tg[ng].ntp,nomE)==1)
	{
		int i=rechEC(tg[ng].te,tg[ng].ntp,nomE),npp=tg[ng].ntp;
		tg[ng].tp[npp-1].ec=tg[ng].te[i];	
	}
		else
		{
	      printf("cette ecuire a deja ses deux pilote\n");
		  (tg[ng].ntp)--;}}
	else 
	  printf("ajout impossible ce pilote est deja saisie \n");
}
void afficheP(grandPrix *tg,int ng)
{
	printf("#############################################\n");
	for(int i=0;i<tg[ng].ntp;i++)
	{
		printf("nom du pilote %s\n",tg[ng].tp[i].nomP);
		printf("prenom du pilote %s\n",tg[ng].tp[i].pernomP);
		printf("nombre du poit du pilote: %d\n",tg[ng].tp[i].nbpP);
		printf("la pays du pilote%s\n",tg[ng].tp[i].pays);
		printf("le nom de leur ecuire:%s\n",tg[ng].tp[i].ec.nomEC);
		printf("le pays de l ecuire :%s\n",tg[ng].tp[i].ec.paysEC);
		printf("le nombre des points de l'ecuire :%d\n",tg[ng].tp[i].ec.nbpEC);
	printf("###############################################\n");
	}
}
void afficheE(grandPrix *tg,int ng)
{
	printf("###########################\n");
	for(int i=0;i<tg[ng].nte;i++)
	{
		printf("le nom de l ecuire :%s\n",tg[ng].te[i].nomEC);
	    printf("le pays de l ecuire :%s\n",tg[ng].te[i].paysEC);
	    printf("le nombre des points de l ecuire :%d\n",tg[ng].te[i].nbpEC);
	printf("###########################\n");
	}

}
void ajourP(grandPrix *tg,int ng,int id)
{
	int p=rechP(tg[ng].tp,tg[ng].ntp,id);
	int r;
	if(p!=-1)
	{
		printf("donner le rang de cet pilote\n");
		scanf("%d",&r);
		switch(r)
		{
			case 1:tg[ng].tp[p].nbpP+=25;
			       printf("mise a jour complette\n");
			       break;
			case 2:tg[ng].tp[p].nbpP+=18;
			       printf("mise a jour complette\n");
			       break;
			case 3:tg[ng].tp[p].nbpP+=15;
			       printf("mise a jour complette\n");
			       break;
		    case 4:tg[ng].tp[p].nbpP+=12;
		           printf("mise a jour complette\n");
			       break;
			case 5:tg[ng].tp[p].nbpP+=10;
			       printf("mise a jour complette\n");
			       break;
			case 6:tg[ng].tp[p].nbpP+=8;
			       printf("mise a jour complette\n");
			       break;
			case 7:tg[ng].tp[p].nbpP+=6;
			       printf("mise a jour complette\n");
			       break;
			case 8:tg[ng].tp[p].nbpP+=4;
			       printf("mise a jour complette\n");
			       break;
		    case 9:tg[ng].tp[p].nbpP+=2;
		           printf("mise a jour complette\n");
			       break;
			case 10:tg[ng].tp[p].nbpP+=1;
			       printf("mise a jour complette\n");
			       break;
			default : printf("ce rong n a pas de point a ajouter");      
		}
	}
	else
	 printf("pilote intouvable\n");
}
void ajourE(grandPrix*tg,int ng)
{
   char nom[20];
   printf("donner votre ecruire\n");
   scanf("%s",nom);
   int p=rechEC(tg[ng].te,tg[ng].nte,nom);
   if(p!=-1)
   {
   	  tg[ng].te[p].nbpEC=0;
      for(int i=0;i<tg[ng].ntp;i++)
       {
   	     if(strcmp(nom,tg[ng].tp[i].ec.nomEC)==0)
   	      tg[ng].te[p].nbpEC+=tg[ng].tp[i].nbpP;
	     }
	  for(int j=0;j<tg[ng].ntp;j++)
	  {
	  	if(strcmp(nom,tg[ng].tp[j].ec.nomEC)==0)
	  	 tg[ng].tp[j].ec.nbpEC=tg[ng].te[p].nbpEC;
	  }
	     } 
	else
	 printf("ecuire inexistant\n");     
}
void supP(grandPrix*tg,int ng,int id)
{
	int p=rechP(tg[ng].tp,tg[ng].ntp,id);
	if(p!=-1)
	{
		for(int i=p;i<tg[ng].ntp;i++)
		 tg[ng].tp[i]=tg[ng].tp[i+1];
		(tg[ng].ntp)--;
		printf("supprimer avec succee");
	}
	else
	  printf("pilote introuvable\n");
}
void supE(grandPrix *tg,int ng,char*nom)
{
	int p=rechEC(tg[ng].te,tg[ng].nte,nom);
	int ep=rechEP(tg[ng].tp,tg[ng].ntp,nom);
	if((p!=-1) && (ep!=-1))
	 {
	  for(int i=0;i<=tg[ng].ntp;i++)
	   {
	   	 while(strcmp(nom,tg[ng].tp[i].ec.nomEC)==0)
	   	     supP(tg,ng,tg[ng].tp[i].id);
            }
	   	for(int j=p;j<tg[ng].nte;j++)
		 tg[ng].te[j]=tg[ng].te[j+1];
		(tg[ng].nte)--;}
	else if((p!=-1) && (ep==-1))
	    {
	    	for(int j=p;j<tg[ng].nte;j++)
		      tg[ng].te[j]=tg[ng].te[j+1];
		    (tg[ng].nte)--;
		}
	else
	 printf("ecuire inexistant\n");
	 
	 }
void ajoutE(grandPrix *tg,int ng,ecuire e)
{
	if(rechEC(tg[ng].te,tg[ng].nte,e.nomEC)==-1)
	   {
	  	tg[ng].te[tg[ng].nte]=e;
	  	(tg[ng].nte)++;
	  	printf("ajout avec succée\n");}
	else
	 printf("ecuire exicte deja\n");

}
void saisirgp(grandPrix *g)
{
	printf("donner le nom du grand prix\n");
	scanf("%s",g->nomC);
	printf("donner le nombre de tour de cette circuit\n");
	scanf("%d",&g->nbtr);
	printf("donner de datte de cette grand prix\n");
	scanf("%s",g->date);
}
void ajoutgp(grandPrix *tg,int*ng, grandPrix g)
{
	int p=rechg(tg,*ng,g.nomC);
	if(p==-1 && *ng<6){
		tg[(*ng)++]=g;}
	else
	printf("cette grand prix deja existe");
}
void afficheg(grandPrix *tg,int ng)
{
	for(int i=0;i<ng;i++)
	{
		printf("#####################################\n");
		printf("le nom du grand prix %s\n",tg[i].nomC);
		printf("le nombre de tour du grand prix :%d\n",tg[i].nbtr);
		printf("le datte de cette grande prix :%s\n",tg[i].date);
		  for(int j=0;j<tg[ng].ntc;j++)
		  {
			printf("le nom du pilote %s\n",tg[i].clas[j].nompp);
			printf("le pays du pilote %s\n",tg[i].clas[j].payspp);
		}
		printf("#####################################\n");
	}
	
}
void ajourg(grandPrix*tg,int ng,char* nom)
{
		int p=rechg(tg,ng,nom);
	if(p!=-1)
	{
		(tg[ng].ntc)=0;
  	for(int i=0;i<tg[ng].ntp;i++)
	{
       strcpy(tg[p].clas[tg[ng].ntc].nompp,tg[ng].tp[i].nomP);
       strcpy(tg[p].clas[tg[ng].ntc].payspp,tg[ng].tp[i].pays);       
       (tg[ng].ntc)++;
	}}
	else
	printf("grand prix introuvable\n");
}
int main()
{
  int np=0,ne=0,ng=0,nc=0;
  pilote tp[20];
  ecuire te[10];
  classement clas[20];
  grandPrix tg[6];
  pilote p;
  ecuire e;
  grandPrix g;
  classement c;
  int choix;
  do
  {
  	system("cls");
  	printf("1:ajouter un pilote\n");
  	printf("2:afficher les pilotes\n");
  	printf("3:afficher les ecuire\n");
  	printf("4:mise a jour du pilote\n");
  	printf("5:supprimer pilote\n");
  	printf("6:ajouter un ecuire\n");
  	printf("7:supprimer un ecuire\n");
  	printf("8:mise a jour de l ecuire\n");
  	printf("9:ajouter un grand prix\n");
  	printf("10:afiicher les grand prix\n");
  	printf("11:mettre ajour un grand prix\n");
  	printf("0:quitter\n");
  	printf("donner votre choix\n");
  	scanf("%d",&choix);
  	switch(choix)
  	{
  		case 1:if(ng==0 )
  		        {
	               printf("il faut ajouter un nouveau garndprix \n");
				  }
				else if (tg[ng].ntp>=20)
				{
					printf("tu as depasser le nombre maximal des pilote vous devez ajouter un nouveau grand prix\n");
				}
				else {
		        saisirP(&p);
                ajoutP(tg,p,ng,&e);}
                system("pause");
                break;
        case 2: afficheP(tg,ng);
                system("pause");
                break;
        case 3: afficheE(tg,ng);
                system("pause");
                break;
        case 4: int id;
                printf("donner l id du pilote\n");
                scanf("%d",&id);
                ajourP(tg,ng,id);
                system("pause");
                break;
        case 5: int iid;
                printf("donner l id du pilote\n");
                scanf("%d",&iid);
                supP(tg,ng,iid);
                system("pause");
                break;
        case 6: if(ng==0 )
  		        {
	               printf("il faut ajouter un nouveau garndprix \n");
				  }
				else if (tg[ng].nte>=10)
				{
					printf("tu as depasser le nombre maximal des ecuire vous devez ajouter un nouveau grand prix\n");
				}
				else{
		         saisirEC(&e);
                ajoutE(tg,ng,e);}
                system("pause");
                break;
        case 7: char supp[20];
                printf("donner l ecuire a supprimer\n");
                scanf("%s",supp);
               	supE(tg,ng,supp);
                system("pause");
                break;
        case 8: ajourE(tg,ng);
                system("pause");
                break;
        case 9: saisirgp(&g);
                ajoutgp(tg,&ng,g);
                system("pause");
                break;
        case 10:afficheg(tg,ng);
                system("pause");
                break;
        case 11:char nnom[20];
                printf("donner le nom du grand prix\n");
                scanf("%s",nnom);
		         ajourg(tg,ng,nnom);
                 system("pause");
                break;
        case 0: exit(0);
        default :printf("choix invalide\n");
	  }
  }while(choix!=0);
}
