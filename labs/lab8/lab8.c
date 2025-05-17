#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


struct person{
	char name[8], surname[16], pol[4];
	int age;
	float heigt;};

void sortn(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (strcmp(hw.name, hr[j].name) < 0); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}

void sortsn(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (strcmp(hw.surname, hr[j].surname) < 0); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}
		
void sortp(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (strcmp(hw.pol, hr[j].pol) > 0); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}
				
void sortd(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (hw.age < hr[j].age); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}

void sorth(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (hw.heigt < hr[j].heigt); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}
		
int main(){
	setlocale(LC_ALL, "Rus");
	char n[8], sn[16], p[4], s[64], s1[64], *f = "text.txt", *f1 = "text1.txt";
	FILE *fr = fopen(f, "r"), *fr1 = fopen(f1, "r");
	int size = 0, j, i, q, m, k;
	while(fgets(s1, sizeof(s1), fr1)){
        size++;}
	fclose(fr1);
	printf("%d\n", size);
	float h;
	struct person hr[size];
	struct person hw[size];

	for(i = 0; i < size; i++){
		if(fgets(s, 64, fr) != NULL){
			sscanf(s,"%s %*s %*d %*s %*f",n), sscanf(s,"%*s %s %*d %*s %*f",sn), \
			sscanf(s,"%*s %*s %d %*s %*f",&m), sscanf(s,"%*s %*s %*d %s %*f",p), \
			sscanf(s,"%*s %*s %*d %*s %f",&h);
			strcpy(hr[i].name, n), strcpy(hr[i].surname, sn), strcpy(hr[i].pol, p);
			strcpy(hw[i].name, n), strcpy(hw[i].surname, sn), strcpy(hw[i].pol, p);			
			hr[i].age = hw[i].age = m;
			hr[i].heigt = hw[i].heigt = h;
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	
	printf("\n==========================\n");
	
									
	printf("name(1)/surname(2)/age(3)/pol(4)/height(5):");
	scanf("%d", &k);
	
	/*sort(hr, k, size);
	for(i = 0; i < size; i++){
		printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}*/
	
	
	if(k == 1){
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 2){
		sortsn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 4){
		sortp(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}			
	if(k == 3){
		sortd(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 5){
		sorth(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 35){
		sorth(hr, size);
		sortd(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 53){
		sortd(hr, size);
		sorth(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 13){
		sortd(hr, size);
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 12){
		sortsn(hr, size);
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 14){
		sortp(hr, size);
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}	
	if(k == 15){
		sorth(hr, size);
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 25){
		sorth(hr, size);
		sortsn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 123){
		sortd(hr, size);
		sortsn(hr, size);
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 125){
		sorth(hr, size);
		sortsn(hr, size);
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	if(k == 1234){
		sortp(hr, size);
		sortd(hr, size);
		sortsn(hr, size);
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].pol, hr[i].heigt);}}
	
	fclose(fr);
	return 0;}
