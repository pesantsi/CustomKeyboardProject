using System;
using System.Collections.Generic;
using System.Text;
using Terminal.Gui;

namespace CustomKeyboardProject.Gui
{
    public class TerminalGuiMenu : MenuBar
    {
        public TerminalGuiMenu()
           : base(new MenuBarItem[1])
        {
            Menus[0] = new MenuBarItem("_File", new MenuItem[] {
                    new MenuItem ("_Open Bitmp File", "", OpenBitmapFile),
                    new MenuItem ("_Quit", "", () => 
                    { 
                        if (Quit ()) 
                            Application.Top.Running = false; 
                    })
                });
        
        }

        private void OpenBitmapFile()
        {
            var d = new OpenDialog("Open Bitmap File", "Open bitmap file for the OLed display");
            d.AllowedFileTypes = new string[] { "*.bmp" };
            d.AllowsMultipleSelection = false;

            Application.Run(d);
        }

        private bool Quit()
        {
            var n = MessageBox.Query(75, 7, "Quit Keyboard Controller", "Are you sure you want to quit the Keyboard Controller?", "Yes", "No");
            return n == 0;
        }
    }
}
