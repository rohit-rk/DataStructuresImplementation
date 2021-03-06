#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *link;
};

struct node *create_list(struct node *);
void display(struct node *);
void search(struct node *,int );
struct node *addatbeg(struct node *,int );
struct node *addatend(struct node *,int );
struct node *addafter(struct node *,int ,int );
struct node *addbefore(struct node *,int ,int);
struct node *addatpos(struct node *,int ,int );
struct node *del(struct node *,int );
struct node *reverse(struct node *);



struct node *addtoempty(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    last=tmp;
    last->link=last;
    return last;
}
struct node *create_list(struct node *last)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    last=NULL;
    if(n==0)
        return last;
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    last=addtoempty(last,data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        last=addatend(last,data);
    }
    return last;
}


struct node *addatbeg(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    return last;
}

struct node *addatend(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
    return last;
}

struct node *addafter(struct node *last,int data,int item)
{
    struct node *tmp,*p;
    p=last->link;
    do
    {
        if(p->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            if(p==last)
                last=tmp;
            return last;
        }
        p=p->link;
    }
    while(p!=last->link);
    printf("%d not present in the list\n",item);
    return last;
}

struct node *del(struct node *last,int data)
{
    struct node *tmp,*p;
    if(last==NULL)
    {
        printf("List is empty\n");
        return last;
    }

    if(last->link==last && last->info==data)
    {
        tmp=last;
        last=NULL;
        free(tmp);
        return last;
    }

    if(last->link->info==data)
    {
        tmp=last->link;
        last->link=tmp->link;
        free(tmp);
        return last;
    }

    p=last->link;
    while(p->link!=last)
    {
        if(p->link->info==data)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return last;
        }
        p=p->link;
    }

    if(last->info==data)
    {
        tmp=last;
        p->link=last->link;
        last=p;
        free(tmp);
        return last;
    }
    printf("Element %d not found\n",data);
    return last;
}

void display(struct node *last)
{
    struct node *p;
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=last->link;
    do
    {
        printf("%d ",p->info);
        p=p->link;
    }
    while(p!=last->link);
    printf("\n");
}

main()
{
    struct node *start=NULL;
    int ch=1,data,item,pos;
    printf("\t\t\t\tCIRCULAR LINKED LIST");
    while(ch!=0)
    {
        printf("\n\n\n\n\n");
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3. Add at beginning\n");
        printf("4.Add at end\n");
        printf("5.Add after node\n");
        printf("6.Delete\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=create_list(start);
            break;
        case 2:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            display(start);
            break;
        case 3:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatbeg(start,data);
            break;
        case 4:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatend(start,data);
            break;
        case 5:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element after which to insert : ");
            scanf("%d",&item);
            start=addafter(start,data,item);
            break;
        case 6:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start=del(start, data);
            break;
        default:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Wrong choice\n");
        }
    }
}
