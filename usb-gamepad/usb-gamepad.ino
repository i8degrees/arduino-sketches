#include "HID.h"
#include "PluggableUSB.h"

#define _USING_HID

#if !defined(_USING_HID)
  #warning "DEPRECATED(jeff): Using HID legacy API, AKA non-pluggable interfaces!"
#else
  // NOTE(jeff): Use the base class APIs for PluggableUSB and PluggableHID interfacing.

// Mouse
static const u8 _hidReportDescriptor[] PROGMEM = {
  0x05, 0x01,     
  0x09, 0x02,     
};

//Mouse_::Mouse_(void) : _buttons(0)
//{
//    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
//    HID().AppendDescriptor(&node);
//}

bool HID_::setup(USBSetup& setup)
{
  if (pluggedInterface != setup.wIndex) {
    return false;
  }
;
  uint8_t request = setup.bRequest;
  uint8_t requestType = setup.bmRequestType;
}

int HID_::getInterface(uint8_t* interfaceCount)
{
  *interfaceCount += 1; // uses 1
  HIDDescriptor hidInterface = {
    D_INTERFACE(pluggedInterface, 1, USB_DEVICE_CLASS_HUMAN_INTERFACE, HID_SUBCLASS_NONE, HID_PROTOCOL_NONE),
    D_HIDREPORT(descriptorSize),
    D_ENDPOINT(USB_ENDPOINT_IN(pluggedEndpoint), USB_ENDPOINT_TYPE_INTERRUPT, USB_EP_SIZE, 0x01)
  };
  
  return USB_SendControl(0, &hidInterface, sizeof(hidInterface));
}
extern HID HID_;
public class App {
  private:
    char* name = "PluggableGamepad";
    char* version = "1.0.0";
  public:
    void App();
    void setup(params);
}

//extern App App;

public class App {
  public:
    App(params) {
      this.setup(this);
    }
    ~App() {
      // Goodbye!
    }
  
    void setup(params) {
      PluggableUSB().plug(params);
    }

    static void Create(params) {
      return new App(params);
    }
}

void setup() {
  App app = App.Create();// App.setup();
  app.setup();
}

void loop() {
  
}

#endif
