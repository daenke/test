using System;
using System.Text;

class HelloWorld {
  static void Main() {
    bool schlussJetzt=false; string inputString;
    StringBuilder inputBuilder = new StringBuilder();

    do {
        Console.WriteLine("Hello World!");
        //ConsoleKeyInfo x = Console.ReadKey();
        while (true)
        {
            ConsoleKeyInfo inputKey = Console.ReadKey(true);
            if (inputKey.Key == ConsoleKey.Enter)
            {
                inputString = inputBuilder.ToString();
                break;
            }
            else if (inputKey.Key == ConsoleKey.Escape)
            {
                inputString = null;
                schlussJetzt=true;
                break;
            }
            else
                inputBuilder.Append(inputKey.KeyChar);
                Console.Write(inputKey.KeyChar);
        }
        Console.WriteLine("");
    } while (schlussJetzt==false);
    Console.WriteLine("Ciao World!");
  }
}
