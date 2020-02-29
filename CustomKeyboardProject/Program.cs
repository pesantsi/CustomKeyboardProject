using CustomKeyboardProject.Gui;
using Mono.Terminal;
using System;
using Terminal.Gui;

namespace CustomeKeyboardProject
{
    //class Demo
    //{
    //    class Box10x : View
    //    {
    //        public Box10x(int x, int y) : base(new Rect(x, y, 10, 10))
    //        {
    //        }

    //        public override void Redraw(Rect region)
    //        {
    //            Driver.SetAttribute(ColorScheme.Focus);

    //            for (int y = 0; y < 10; y++)
    //            {
    //                Move(0, y);
    //                for (int x = 0; x < 10; x++)
    //                {

    //                    Driver.AddRune((Rune)('0' + (x + y) % 10));
    //                }
    //            }

    //        }
    //    }

    //    class Filler : View
    //    {
    //        public Filler(Rect rect) : base(rect)
    //        {
    //        }

    //        public override void Redraw(Rect region)
    //        {
    //            Driver.SetAttribute(ColorScheme.Focus);
    //            var f = Frame;

    //            for (int y = 0; y < f.Width; y++)
    //            {
    //                Move(0, y);
    //                for (int x = 0; x < f.Height; x++)
    //                {
    //                    Rune r;
    //                    switch (x % 3)
    //                    {
    //                        case 0:
    //                            r = '.';
    //                            break;
    //                        case 1:
    //                            r = 'o';
    //                            break;
    //                        default:
    //                            r = 'O';
    //                            break;
    //                    }
    //                    Driver.AddRune(r);
    //                }
    //            }
    //        }
    //    }


    //    static void ShowTextAlignments(View container)
    //    {
    //        container.Add(
    //            new Label(new Rect(0, 0, 40, 3), "1-Hello world, how are you doing today") { TextAlignment = TextAlignment.Left },
    //            new Label(new Rect(0, 4, 40, 3), "2-Hello world, how are you doing today") { TextAlignment = TextAlignment.Right },
    //            new Label(new Rect(0, 8, 40, 3), "3-Hello world, how are you doing today") { TextAlignment = TextAlignment.Centered },
    //            new Label(new Rect(0, 12, 40, 3), "4-Hello world, how are you doing today") { TextAlignment = TextAlignment.Justified });
    //    }

    //    static void ShowEntries(View container)
    //    {
    //        var scrollView = new ScrollView(new Rect(50, 10, 20, 8))
    //        {
    //            ContentSize = new Size(100, 100),
    //            ContentOffset = new Point(-1, -1),
    //            ShowVerticalScrollIndicator = true,
    //            ShowHorizontalScrollIndicator = true
    //        };

    //        scrollView.Add(new Box10x(0, 0));
    //        //scrollView.Add (new Filler (new Rect (0, 0, 40, 40)));

    //        // This is just to debug the visuals of the scrollview when small
    //        var scrollView2 = new ScrollView(new Rect(72, 10, 3, 3))
    //        {
    //            ContentSize = new Size(100, 100),
    //            ShowVerticalScrollIndicator = true,
    //            ShowHorizontalScrollIndicator = true
    //        };
    //        scrollView2.Add(new Box10x(0, 0));
    //        var progress = new ProgressBar(new Rect(68, 1, 10, 1));
    //        bool timer(MainLoop caller)
    //        {
    //            progress.Pulse();
    //            return true;
    //        }

    //        Application.MainLoop.AddTimeout(TimeSpan.FromMilliseconds(300), timer);

    //        // A little convoluted, this is because I am using this to test the
    //        // layout based on referencing elements of another view:

    //        var login = new Label("Login: ") { X = 3, Y = 6 };
    //        var password = new Label("Password: ")
    //        {
    //            X = Pos.Left(login),
    //            Y = Pos.Bottom(login) + 1
    //        };
    //        var loginText = new TextField("")
    //        {
    //            X = Pos.Right(password),
    //            Y = Pos.Top(login),
    //            Width = 40
    //        };
    //        var passText = new TextField("")
    //        {
    //            Secret = true,
    //            X = Pos.Left(loginText),
    //            Y = Pos.Top(password),
    //            Width = Dim.Width(loginText)
    //        };

    //        // Add some content
    //        container.Add(
    //            login,
    //            loginText,
    //            password,
    //            passText,
    //            new FrameView(new Rect(3, 10, 25, 6), "Options"){
    //            new CheckBox (1, 0, "Remember me"),
    //            new RadioGroup (1, 2, new [] { "_Personal", "_Company" }),
    //            },
    //            new ListView(new Rect(60, 6, 16, 4), new string[] {
    //            "First row",
    //            "<>",
    //            "This is a very long row that should overflow what is shown",
    //            "4th",
    //            "There is an empty slot on the second row",
    //            "Whoa",
    //            "This is so cool"
    //            }),
    //            scrollView,
    //            //scrollView2,
    //            new Button("Ok") { X = 3, Y = 19 },
    //            new Button("Cancel") { X = 10, Y = 19 },
    //            progress,
    //            new Label("Press F9 (on Unix ESC+9 is an alias) to activate the menubar") { X = 3, Y = 22 }
    //        );

    //    }

    //    public static Label ml2;

    //    static void NewFile()
    //    {
    //        var d = new Dialog(
    //            "New File", 50, 20,
    //            new Button("Ok", is_default: true) { Clicked = () => { Application.RequestStop(); } },
    //            new Button("Cancel") { Clicked = () => { Application.RequestStop(); } });
    //        ml2 = new Label(1, 1, "Mouse Debug Line");
    //        d.Add(ml2);
    //        Application.Run(d);
    //    }

    //    static bool Quit()
    //    {
    //        var n = MessageBox.Query(50, 7, "Quit Demo", "Are you sure you want to quit this demo?", "Yes", "No");
    //        return n == 0;
    //    }

    //    static void Close()
    //    {
    //        MessageBox.ErrorQuery(50, 5, "Error", "There is nothing to close", "Ok");
    //    }

    //    public static Label ml;

    class Program
    {
        static void Main()
        {
            Application.Init();

            Colors.Base = new ColorScheme();
            Colors.Dialog = new ColorScheme();
            Colors.Menu = new ColorScheme();
            Colors.Error = new ColorScheme();

            Colors.Base.Normal = Application.Driver.MakeAttribute(Color.White, Color.Black);
            Colors.Base.Focus = Application.Driver.MakeAttribute(Color.White, Color.Cyan);
            Colors.Base.HotNormal = Application.Driver.MakeAttribute(Color.BrightYellow, Color.Blue);
            Colors.Base.HotFocus = Application.Driver.MakeAttribute(Color.BrightYellow, Color.Cyan);

            Colors.Menu.HotFocus = Application.Driver.MakeAttribute(Color.BrightYellow, Color.Black);
            Colors.Menu.Focus = Application.Driver.MakeAttribute(Color.White, Color.Black);
            Colors.Menu.HotNormal = Application.Driver.MakeAttribute(Color.BrightYellow, Color.Cyan);
            Colors.Menu.Normal = Application.Driver.MakeAttribute(Color.White, Color.Black);

            Colors.Dialog.Normal = Application.Driver.MakeAttribute(Color.Black, Color.Gray);
            Colors.Dialog.Focus = Application.Driver.MakeAttribute(Color.Black, Color.Cyan);
            Colors.Dialog.HotNormal = Application.Driver.MakeAttribute(Color.Blue, Color.Gray);
            Colors.Dialog.HotFocus = Application.Driver.MakeAttribute(Color.Blue, Color.Cyan);

            Colors.Error.Normal = Application.Driver.MakeAttribute(Color.White, Color.Red);
            Colors.Error.Focus = Application.Driver.MakeAttribute(Color.Black, Color.Gray);
            Colors.Error.HotNormal = Application.Driver.MakeAttribute(Color.BrightYellow, Color.Red);
            Colors.Error.HotFocus = Colors.Error.HotNormal;

            var top = Application.Top;
            top.Add(new TerminalGuiMenu(), new TerminalGuiWindow());

            Application.Run();
        }
    }
}
