#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct
{
	float x, y, z;

}Vrh;

typedef struct
{
	float normalax;
	float normalay;
	float normalaz;

	Vrh v1, v2, v3;

	unsigned short boja;
}Trokut;

typedef struct
{
	int broj;
	Trokut* nizTrokuta;
}Objekt3D;



Objekt3D *citaj(FILE *fp)
{
	Objekt3D* binarna = (Objekt3D*)malloc(sizeof(Objekt3D));
	fseek(fp,80, SEEK_SET);
	int t;
	fread(&t, 4, 1, fp);
	Trokut* niztrokuta = (Trokut*)malloc(t * sizeof(Trokut));
	for (int i = 0; i < t; i++)
	{
		fread(&(niztrokuta[i]),50,1,fp);
	}
	binarna->nizTrokuta = niztrokuta;
	binarna->broj = t;
	return binarna;
}

void pisibin(Objekt3D* bin, FILE* fpb)
{
	char zaglavlje[80] = { 0 };
	fwrite(zaglavlje, 1, 80, fpb);
	fwrite(&(bin->broj), 4, 1, fpb);
	for (int i = 0; i < bin->broj; i++)
	{
		fwrite(&(bin->nizTrokuta[i]),50,1,fpb);
	}
}

void pisitxt(Objekt3D* bin, FILE* fpt)
{
	fprintf(fpt, "%s\n", "solid tekstualni format");
	for (int i = 0; i < bin->broj; i++)
	{
		fprintf(fpt,"%s %f %f %f\n","  facet normal", bin->nizTrokuta[i].normalax, bin->nizTrokuta[i].normalay, bin->nizTrokuta[i].normalaz);
		fprintf(fpt, "%s\n", "    outer loop");
		fprintf(fpt, "%s %f %f %f\n","      vertex", bin->nizTrokuta[i].v1.x, bin->nizTrokuta[i].v1.y, bin->nizTrokuta[i].v1.z);
		fprintf(fpt, "%s %f %f %f\n", "      vertex", bin->nizTrokuta[i].v2.x, bin->nizTrokuta[i].v2.y, bin->nizTrokuta[i].v2.z);
		fprintf(fpt, "%s %f %f %f\n", "      vertex", bin->nizTrokuta[i].v3.x, bin->nizTrokuta[i].v3.y, bin->nizTrokuta[i].v3.z);
		fprintf(fpt, "%s\n","    endloop");
		fprintf(fpt, "%s\n","  endfacet");
	}
	fprintf(fpt, "%s\n", "endsolid");
}

void brisi(Objekt3D* bin)
{
	free(bin->nizTrokuta);
	free(bin);
}

void main()
{
	FILE* fp = fopen("primjerbin.stl","rb");
	Objekt3D* bin = citaj(fp);
	fclose(fp);
	FILE* fpb = fopen("novibin.stl","wb");
	pisibin(bin,fpb);
	fclose(fpb);
	FILE* fpt = fopen("novitxt.stl", "wt");
	pisitxt(bin,fpt);
	fclose(fpt);
	brisi(bin);

}


