import java.util.Scanner;

class a extends Exception {

    a() {

        System.out.println("not legeal age");

    }

};

class emp {
    int id, age;
    String name, desg;
};

class main1 {
    public static void main(String a[]) {
        try (Scanner sc = new Scanner(System.in)) {
            int n;

            System.out.println("enter no of emp");
            n = sc.nextInt();
            emp e[] = new emp[n];
            e[0] = new emp();
            e[0].name = a[0];
            e[0].age = Integer.parseInt(a[1]);
            e[0].desg = a[2];
            e[0].id = Integer.parseInt(a[3]);
            String na, d;
            int ag, i;
            while ((n - 1) > 0) {
                e[n - 1] = new emp();
                System.out.println("enter name");
                na = sc.next();
                e[n - 1].name = na;
                System.out.println("enter age");
                ag = sc.nextInt();
                e[n - 1].age = ag;
                if (ag < 18) {
                    try {
                        throw new a();
                    } catch (a c) {
                        System.out.println("enetr age again");
                        ag = sc.nextInt();
                    }
                }
                System.out.println("enter desigantion");
                d = sc.nextLine();
                e[n - 1].desg = d;
                System.out.println("enetr id");
                i = sc.nextInt();
                e[n - 1].id = i;
                n--;

            }
        } catch (NumberFormatException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}