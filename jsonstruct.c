// structure format for printing the given JSON
struct contact_persons
{
    char *contact_person_id;
    char *first_name;
    char *last_name;
    char *e_mail;    
};
struct contact
{
    char *contact_id;
    char *contact_name;
    char *street;
    char *area;
    char *city;
    struct contact *contact_persons;
}*c;

   
