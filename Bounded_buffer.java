package oslab;
import java.util.Scanner;
public class Oslab {
    static int s=1,e=10,f=0, j=1,k=1;
    static int wait(int s)
    {
     return --s; 
    }
    static int signal(int s)
    {
        return ++s;
    }
    static void producer()
    {
        s=wait(s);
        e=wait(e);
        f=signal(f);
        System.out.println("Producer produces"+j+"Item");
        j++;
        s=signal(s);
    }
    static void consumer()
    {
        s=wait(s);
        e=signal(e);
        f=wait(f);
        System.out.println("Consumer Consumes" + k +"th item");
        s=signal(s);
    }
    public static void main(String[] args) {
        while(true)
        {    
            System.out.println("1. Produces 2.Consumer 3. Exit");
            Scanner inp=new Scanner(System.in);
            int choice=inp.nextInt();
            switch(choice)
            {
                case 1: if(s == 1 && e != 0)
                       {
                            producer();
                            
                       }
                       else
                         {
                              System.out.println("Producer is waiting");
                         }
                        break;
                case 2: if(s==1 && f!=0)
                        {
                            consumer();
                        }
                        else
                         {
                              System.out.println("Consumer is waiting");
                         }
                        break;
                case 3: System.exit(0);
            }
       }
    }
}
