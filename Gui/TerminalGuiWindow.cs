using System;
using System.Collections.Generic;
using System.Text;
using Terminal.Gui;

namespace CustomKeyboardProject.Gui
{
    public class TerminalGuiWindow : Window
    {
        public static Label ml2;

        static void NewFile()
        {
            var d = new OpenDialog("Open File", "Open File Message");
            Application.Run(d);
        }

        static bool Quit()
        {
            var n = MessageBox.Query(50, 7, "Quit Demo", "Are you sure you want to quit this demo?", "Yes", "No");
            return n == 0;
        }

        static void Close()
        {
            MessageBox.ErrorQuery(50, 5, "Error", "There is nothing to close", "Ok");
        }

        public TerminalGuiWindow()
            : base("Custom Keyboard Controller")
        {
            X = 0;
            Y = 1;
            Width = Dim.Fill();
            Height = Dim.Fill();
            
            var customTextLabel = new Label("Custom Text: ") { X = 1, Y = 1 };
            var customTextLabelText = new TextField("")
            {
                X = Pos.Left(customTextLabel),
                Y = Pos.Bottom(customTextLabel),
                Width = 40
            };

            Add(customTextLabel, customTextLabelText);
            ////        var passText = new TextField("")
            ////        {
            ////            Secret = true,
            ////            X = Pos.Left(loginText),
            ////            Y = Pos.Top(password),
            ////            Width = Dim.Width(loginText)
            ////        };

            ////        // Add some content
            ////        container.Add(
            ////            login,
            ////            loginText,
            ////            password,
            ////            passText,
            ////            new FrameView(new Rect(3, 10, 25, 6), "Options"){
            ////            new CheckBox (1, 0, "Remember me"),
            ////            new RadioGroup (1, 2, new [] { "_Personal", "_Company" }),
            ////            },
            ////            new ListView(new Rect(60, 6, 16, 4), new string[] {
            ////            "First row",
            ////            "<>",
            ////            "This is a very long row that should overflow what is shown",
            ////            "4th",
            ////            "There is an empty slot on the second row",
            ////            "Whoa",
            ////            "This is so cool"
            ////            }),
            ////            scrollView,
            ////            //scrollView2,
            ////            new Button("Ok") { X = 3, Y = 19 },
            ////            new Button("Cancel") { X = 10, Y = 19 },
            ////            progress,
            ////            new Label("Press F9 (on Unix ESC+9 is an alias) to activate the menubar") { X = 3, Y = 22 }
            ////        );


            ////    var menu = new MenuBar(new MenuBarItem[] {
            ////    new MenuBarItem ("_File", new MenuItem [] {
            ////        new MenuItem ("_New", "Creates new file", NewFile),
            ////        new MenuItem ("_Open", "", null),
            ////        new MenuItem ("_Close", "", () => Close ()),
            ////        new MenuItem ("_Quit", "", () => { if (Quit ()) top.Running = false; })
            ////    }),
            ////    new MenuBarItem ("_Edit", new MenuItem [] {
            ////        new MenuItem ("_Copy", "", null),
            ////        new MenuItem ("C_ut", "", null),
            ////        new MenuItem ("_Paste", "", null)
            ////    })
            ////});

            ////ShowEntries(win);
            ////int count = 0;
            ////ml = new Label(new Rect(3, 17, 47, 1), "Mouse: ");
            ////Application.RootMouseEvent += delegate (MouseEvent me)
            ////{
            ////    ml.Text = $"Mouse: ({me.X},{me.Y}) - {me.Flags} {count++}";
            ////};

            ////win.Add(ml);

            ////top.Add(win, menu);
            ////top.Add(menu);

            //top.Add(win);
        }
    }
}
