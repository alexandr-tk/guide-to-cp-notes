    import java.util.*;
    import java.io.*;

    final class FastScanner {
        private final InputStream in; private final byte[] buf = new byte[1<<16];
        private int ptr=0, len=0;
        FastScanner(InputStream is){ in=is; }
        private int read(){ if(ptr>=len){ try{ len=in.read(buf); ptr=0; }catch(Exception e){ return -1; } if(len<=0) return -1; } return buf[ptr++]; }
        int nextInt(){ int c, s=1, x=0; do c=read(); while(c<=32);
            if(c=='-'){ s=-1; c=read(); }
            while(c>32){ x = x*10 + (c-'0'); c=read(); }
            return x*s; }
    }



    class Triple implements Comparable<Triple> {
        int a,b,c;

        Triple(int a, int b, int c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override

        public int compareTo(Triple other)
        {
            if(this.b!=other.b) return Integer.compare(this.b, other.b);
            if(this.c!=other.c) return Integer.compare(other.c, this.c);
            return Integer.compare(this.a, other.a);

        }
    }

    public class Projects {
        
        public static void main(String[] args)
        {
            FastScanner sc = new FastScanner(System.in);

            int n = sc.nextInt();
        
            List<Triple> projects = new ArrayList<>();
            long[] dp = new long[n];

            for(int i=0; i<n; i++){
                int a = sc.nextInt();
                int b = sc.nextInt();
                int c = sc.nextInt();
                Triple project = new Triple(a, b, c);
                projects.add(project);
            }

            Collections.sort(projects);

            for(int i=0; i<n; i++){
                Triple project = projects.get(i);
                
                int start_t = project.a;
               
                Triple key = new Triple(Integer.MIN_VALUE, start_t, Integer.MAX_VALUE);
                int pos = Collections.binarySearch(projects, key);
                if(pos<0) pos = -pos - 1;


                if(pos != 0 ){
                    dp[i] = Math.max(project.c + dp[pos-1],dp[i-1]);
                }
                else if(i!=0) dp[i] = Math.max(project.c,dp[i-1]);
                else dp[i] = project.c;

            }

            System.out.println(dp[n-1]);

        }

    }
