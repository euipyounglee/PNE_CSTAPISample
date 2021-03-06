using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CSharp_Application_Sample
{

    [StructLayout(LayoutKind.Explicit)]
    public struct CTS_CAN_VALUE
    {
        [FieldOffset(0)]
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
        public int[] lVal;

        [FieldOffset(0)]
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
        public float[] fVal;

        [FieldOffset(0)]
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
        public SByte[] strVal;
    }
}
