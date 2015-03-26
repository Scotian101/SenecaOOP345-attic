#include <iostream>
using namespace std;

// http://www.learncpp.com/cpp-tutorial/VirtualBaseVirtualBase7-multiple-inheritance/
//
// MI : Multiple Inheritence
//  - not available in SmallTalk or PHP
//  - Java and C# restricted to interface classes
//  - some believe more problems with MI than it solves
//
// diamond pattern
//
//       ---------PoweredDevice---------
//       |                             |
//       |                             |
//       V                             V
//    Scanner                       Printer
//       |                             |
//       |                             |
//       -------->PhotoCopier<----------
//
// A scanner is a powered device
// A printer is a powered device
// A photocopier is both a scanner and a printer

// Should there be two copies of the base class or single?
// Do we replicate the base class data members and associated member functions in Scanner and Printer?

// controlled by 'virtual base class'

///////////////////////////////////////////////////////////////////////////////

class PoweredDevice { // base class for everything
int x[10000];
char y[10000];
public: PoweredDevice () { cout << "PoweredDevice ctor size=" << sizeof(PoweredDevice) << endl; }
};

///////////////////////////////////////////////////////////////////////////////

class Scanner : public PoweredDevice {
public: Scanner () { cout << "Scanner ctor size=" << sizeof(Scanner) << endl;}
};

class Printer : public PoweredDevice {
public: Printer () { cout << "Printer ctor size=" << sizeof(Printer) << endl;}
};

class PhotoCopier : public Scanner, public Printer {
public: PhotoCopier () { cout << "PhotoCopier ctor size=" << sizeof(PhotoCopier) << endl;}
};

///////////////////////////////////////////////////////////////////////////////

class ScannerVirtualBase : virtual public PoweredDevice {  // single shared instance of base class
public: ScannerVirtualBase () { cout << "ScannerVirtualBase ctor size=" << sizeof(ScannerVirtualBase) << endl; }
};

class PrinterVirtualBase : virtual public PoweredDevice {  // single shared instance of base class
public: PrinterVirtualBase () { cout << "PrinterVirtualBase ctor size=" << sizeof(PrinterVirtualBase) << endl; }
};

class PhotoCopierVirtualBase : public ScannerVirtualBase, public PrinterVirtualBase {
public: PhotoCopierVirtualBase () { cout << "PhotoCopier ctor size=" << sizeof(PhotoCopierVirtualBase) << endl;  }
};

///////////////////////////////////////////////////////////////////////////////

int main (int argc, char**argv)
{
    cout << endl << argv[0] << endl << endl;

    cout << "PhotoCopier - creates a pair of instances of 'base class' PoweredDevice\n";
    cout << "Note: PoweredDevice ctor called twice:\n";
    PhotoCopier objPhotoCopier;

    cout << endl;

    cout << "PhotoCopierVirtualBase - 'virtual PoweredDevice' creates a single instance of 'base class' PoweredDevice\n";
    cout << "Note: PoweredDevice ctor called once:\n";
    PhotoCopierVirtualBase objPhotoCopierVirtualBase;
}

