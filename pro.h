void menu(void);
void pat(void);
//void emp(void); 
//void inv(void);
void verification(void);
void add_pat(void);
void mod_pat(void);
void search_pat(void); 
void list_pat(void);
void delete_pat(void);			
			

struct address{
        int hno;
        char street[40];
        char city[40];
        char state[40];
};

struct patient{

                char name[40];
                char fname[40];
                int age;
                char bg[3];
                char gender[10];
                char regn[10];
                struct address a;
                char ph[10];
                char disease[60];
                char doc_name[40];
                char history[200];
                char date[10];
                char treatment[40];
                char med[40];
};

struct staff{

                char name[40];
                int age;
                char bg[3];
                char gender[10];
                char uid[10];
                struct address b;
                char ph[10];
                double salary;
                char desig[40];
};

struct inventory{

                int sno;
                char name[30];
                char dop[20];
                int qnty;
                float price;
                float amount;
};



