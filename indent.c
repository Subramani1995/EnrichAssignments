//to convert the given file into JASON string format

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct persons
{
    char *person_id;
    char *name;
    char *mail_id;
};
struct contacts
{
    char *contact_id;
    char *contact_name;
    char *city;
    struct persons p[2];
}c[]={{"1111","subramani","chennai",{"345","karthik","karthik@gmail.com","333","bharad","waj@gmail.com"}},
      {"1234","vadivel","Dubai",{"5555","kishore","hk@gmail.com","3333","hari","haran@gmail.com"}}};

void tostring(struct contacts * ,char *,int,int);

int main()
{
    char ans[5000];
    int num1=2;     //no of contacts
    int num2=2;     //no of persons
    tostring(&c,&ans,num1,num2);
    printf("%s",ans);
    return 0;
}
void tostring(struct contacts *c,char *ans,int no_of_contacts,int no_of_persons)
{
    int i,j;
    strcat(ans,"[\n");
    for(i=0;i<no_of_contacts;i++)
    {
        strcat(ans,"  {");
        strcat(ans,"\n\tcontact_id: \"");
        strcat(ans,c[i].contact_id);
        strcat(ans,"\",\n\tcontact_name: \"");
        strcat(ans,c[i].contact_name);
        strcat(ans,"\",\n\tcity: \"");
        strcat(ans,c[i].city);
        strcat(ans,"\",");
        
        strcat(ans,"\n\tContact_persons: [\n");
        for(j=0;j<no_of_persons;j++)
        {
            strcat(ans,"\t    {\n");
            strcat(ans,"\t\tperson_id: \"");
            strcat(ans,c[i].p[j].person_id);
            strcat(ans,"\",\n\t\tperson_name: \"");
            strcat(ans,c[i].p[j].name);
            strcat(ans,"\",\n\t\tperson mail id: \"");
            strcat(ans,c[i].p[j].mail_id);
            strcat(ans,"\",\n\t    },\n");
        }
        strcat(ans,"\t]\n  },\n");
        
    }
    strcat(ans,"]");   
}
   
