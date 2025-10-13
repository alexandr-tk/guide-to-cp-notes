import java.util.*;

public class MountainRange {

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        int[] mountains = new int[n];
        int ans = 1;
        int visits = 1;
        

        for(int i=0; i<n; i++)
        {
            mountains[i] = sc.nextInt();
        }

        int maxHeight = Integer.MIN_VALUE;

        for(int i=0; i<n; i++)
        {
            if(mountains[i]>maxHeight)
            {
                
                visits = 0;
                maxHeight = mountains[i];
            }
            visits++;
            ans = Math.max(ans, visits);
        }

        visits=1;
        maxHeight = Integer.MIN_VALUE;
        for(int i=n-1; i>=0; i--)
        {
            if(mountains[i]>maxHeight)
            {
                
                visits = 0;
                maxHeight = mountains[i];
            }
            visits++;
            ans = Math.max(ans, visits);
        }
        


        System.out.println(ans);

    }
}