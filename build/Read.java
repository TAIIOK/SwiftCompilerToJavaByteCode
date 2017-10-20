import java.util.Scanner;

public final class Read
{
    static Scanner in = new Scanner(System.in);

    public static int Int(String i)
    {

        int foo = Integer.parseInt(i);

        return foo;
    }

    public static float Float(String i)
    {
        float foo = Float.parseFloat(i);
        return foo;
    }

    public static String readString()
    {
        return in.nextLine();
    }

    public static boolean Bool()
    {
        return in.nextBoolean();
    }

    public static char readChar()
    {
        return in.next().charAt(0);
    }
}
