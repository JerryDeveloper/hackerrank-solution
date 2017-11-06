import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static String super_reduced_string(String s){
        boolean cleaned = false;
        while(!cleaned)
        {
            StringBuilder sb = new StringBuilder("");
            cleaned = true;
            int i = 0;
            for(; i < s.length() - 1; ++i)
            {
                if(s.charAt(i) == s.charAt(i + 1))
                {
                    cleaned = false;
                    ++i;
                    continue;
                }
                sb.append(s.charAt(i));
            }
            
            if(i == s.length() - 1)
                sb.append(s.charAt(i));
            s = sb.toString();
        }
        
        if(s.length() == 0)
            s = "Empty String";
        
        return s;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String result = super_reduced_string(s);
        System.out.println(result);
    }
}
