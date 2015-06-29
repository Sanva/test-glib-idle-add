
using System;
using Gtk;

public class GtkTest {

  public static void Main ()
  {
    Application.Init ();

    Button button = new Button ("Test");
    button.Clicked += new EventHandler (ButtonClickedHandler);

    Window myWin = new Window ("GTK# Test Application");
    myWin.Add (button);
    myWin.Resize (400, 250);
    myWin.DeleteEvent += WindowDeleteEventHandler;
    myWin.ShowAll ();
    
    Application.Run ();
  }
  
  static void ButtonClickedHandler (object obj, EventArgs args)
  {
    GLib.Idle.Add (delegate {
      Console.WriteLine ("Idle!");

      return false; // Changing this to `true` removes critical warnings.
    });
  }
  
  public static void WindowDeleteEventHandler (object obj, DeleteEventArgs args)
  {
    Application.Quit ();
  }

}
