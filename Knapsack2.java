/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package knapsack2.cpp;

/**
 *
 * @author shaha
 */

import java.util.Scanner;

import static java.lang.Math.min;

public class Knapsack2 {



    static final int N = 101;
    static long W, n;

    static long[] v = new long[N], w = new long[N];
    static long[][] mW = new  long[N][100001], dp = new long[N][100001];

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        
        System.out.println("Enter Number of items:");

        n = scn.nextInt();
        
        System.out.println("Enter capacity of knapsack");
        W = scn.nextInt();
   
        System.out.println("Enter weight and value in that order");
        for (int i = 1; i <= n; i++) {
            w[i] = scn.nextLong();
            v[i] = scn.nextLong();
        }

        for (int i = 0; i <= n; i++) {
            for (int val = 0; val < 100001; val++) {
                mW[i][val] = (long) 1e13;
            }
        }

        dp[0][0] = 1;
        mW[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int val = 0; val < 100001; val++) {
                // not taking
                if (dp[i - 1][val] != 0) {
                    dp[i][val] = 1;
                    mW[i][val] = min(mW[i][val], mW[i - 1][val]);
                }
                // taking item
                if (val - v[i] >= 0 && dp[i - 1][(int) (val - v[i])] != 0
                        && mW[i - 1][(int) (val - v[i])] + w[i] <= W)
                {
                    dp[i][val] = 1;
                    mW[i][val] = min(mW[i][val], mW[i - 1][(int) (val - v[i])] + w[i]);
                     System.out.println("weight->"+mW[i][val]+"  val->"+val);
                    
                }
            }
        }

        int ans = 0;
        for (int val = 0; val < 100001; val++) {
            if (dp[(int) n][val] != 0) ans = val;
              
          
        }

        
      /*  for (int i = 1; i <= n; i++) {
            for (int val = 0; val < 100001; val++){
                
             if (val - v[i] >= 0 && dp[i - 1][(int) (val - v[i])] != 0
                        && mW[i - 1][(int) (val - v[i])] + w[i] <= W && dp[i][val]==1 && mW[i][val]==mW[i - 1][(int) (val - v[i])] + w[i])
             {
                 System.out.println(w[i]);
             }
                    
                    
            }
            }*/
      
     
        System.out.println("Maximum possible sum of values is "+ans);
        
     
       }
        
        

    }
