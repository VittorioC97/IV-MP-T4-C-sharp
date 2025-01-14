﻿using System.Collections.Generic;

namespace ServerLauncher
{
    class Configuration
    {
        public int port { get; set; }
        public string name { get; set; }
        public string url { get; set; }
        public string location { get; set; }
        public bool masterList { get; set; }
        public bool gtaIV { get; set; }
        public List<string> modules { get; set; }
}
}
