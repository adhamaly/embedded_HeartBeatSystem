# Smart Wearable Health Monitoring System
![cover](https://github.com/adhamaly/Smart-Wearable-Health-Monitoring-System/blob/main/images/cover.jpg)

The main purpose of the project is to help people to monitor main information about their heart health (BPM), to know whether they are suffering from any heart disease using smart wearable device that will collect basic data like heart rate, using the techniques of machine learning in an android app that help in determining the status of user Our project is oriented to normal users (especially old people) .

#  Demo
![enter image description here](https://github.com/adhamaly/Smart-Wearable-Health-Monitoring-System/blob/main/images/WhatsApp%20Image%202020-07-13%20at%204.43.17%20AM%20%282%29.jpeg)

# Used Software & Hardware



**1.  ATmega32 Microcontroller**

**1.1 Overview**

The Atmel AVR ATmega32 is a high-performance, low-power Microchip 8-bit AVR RISC-based microcontroller combines 32KB ISP flash memory with read-while-write capabilities, 1KB EEPROM, 2KB SRAM, 54/69 general purpose I/O lines, 32 general purpose working registers, a JTAG interface for boundary-scan and on-chip debugging/programming, three flexible timer/counters with compare modes, internal and external interrupts, serial programmable USART, a universal serial interface (USI) with start condition detector, an 8-channel 10-bit A/D converter, programmable watchdog timer with internal oscillator, SPI serial port, and five software selectable power saving modes. The device operates between 1.8-5.5 volts.

![enter image description here](https://github.com/adhamaly/Smart-Wearable-Health-Monitoring-System/blob/main/images/at_pins.jpg)




**2. Pulse Sensor**

**2.1 Pulse sensor working principle**

The working of the Pulse/Heart beat sensor is very simple. The sensor has two sides, on one side the LED is placed along with an ambient light sensor and on the other side we have some circuitry. This circuitry is responsible for the amplification and noise cancellation work. The LED on the front side of the sensor is placed over a vein in our human body. This can either be your Finger tip or you ear tips, but it should be placed directly on top of a vein.
Now the LED emits light which will fall on the vein directly. The veins will have blood flow inside them only when the heart is pumping, so if we monitor the flow of blood we can monitor the heart beats as well. If the flow of blood is detected then the ambient light sensor will pick up more lights since they will be reflected ted by the blood, this minor change in received light is analyzed over time to determine our heart beats.

![enter image description here](https://github.com/adhamaly/Smart-Wearable-Health-Monitoring-System/blob/main/images/11574-04_pulseSensor.jpg)


## Libraries support Embedded System (Implemented from Scratch using Embedded C)

**1. Software module ADC Library/Driver**
 it is a Software module ADC Driver which represent interface to ADC (Analog To Digital Converter) Hardware circuit in Microcontroller which is used for convert analog signals into digital signals to be proceeds by Micro-processor in Microcontroller
 
**2. LCD driver**
It is a software driver/library which developed for enabling Microcontroller interact with it LCD for sending data to LCD display.

**3.  Timer driver**
It is a software driver/library which represent interface for handling TIMER module in Microcontroller.

**4. UART (Bluetooth communication) Library/driver**
Bluetooth module based on UART communication module which used for Serial communication 

## Android Used API 

**1. Android Bluetooth APIs**
these APIs let applications wirelessly connect to other Bluetooth devices, enabling point-to-point and multipoint wireless features.
Using the Bluetooth APIs, an Android application can perform the following:
- Scan for other Bluetooth devices
- Query the local Bluetooth adapter for paired Bluetooth devices
- Transfer data to and from other devices
        
    Key classes and interfaces

[BluetoothAdapter](https://developer.android.com/reference/android/bluetooth/BluetoothAdapter) is the entry-point for all Bluetooth interaction. Using this, you can discover other Bluetooth devices, query a list of bonded (paired) devices

[BluetoothDevice](https://developer.android.com/reference/android/bluetooth/BluetoothDevice)
Represents a remote Bluetooth device. Use this to request a connection with a remote device through a [BluetoothSocket](https://developer.android.com/reference/android/bluetooth/BluetoothSocket) or query information about the device such as its name, address, class, and bonding state.

[BluetoothSocket](https://developer.android.com/reference/android/bluetooth/BluetoothSocket)
Represents the interface for a Bluetooth socket (similar to a TCP [Socket](https://developer.android.com/reference/java/net/Socket)). This is the connection point that allows an application to exchange data with another Bluetooth device using [InputStream](https://developer.android.com/reference/java/io/InputStream) and [OutputStream](https://developer.android.com/reference/java/io/OutputStream).

**2. Maps API**

Using the Google Play services location APIs, your app can request the last known location of the user's device. In most cases, you are interested in the user's current location, which is usually equivalent to the last known location of the device.

Specifically, use the [fused location provider](https://developers.google.com/android/reference/com/google/android/gms/location/FusedLocationProviderClient.html) to retrieve the device's last known location. The fused location provider is one of the location APIs in Google Play services. It manages the underlying location technology and provides a simple API so that you can specify requirements at a high level, like high accuracy or low power. It also optimizes the device's use of battery power.


**Key classes and interfaces**

public class **FusedLocationProviderClient**

The main entry point for interacting with the fused location provider.
#### **public Task<**[**Location**](https://developer.android.com/reference/android/location/Location.html)**>**  getLastLocation  **()**

Returns the best most recent location currently available.

**3.  PyTorch Android API**

Running ML on edge devices is growing in importance as applications continue to demand lower latency. It is also a foundational element for privacy-preserving techniques such as federated learning. As of PyTorch 1.3, PyTorch supports an end-to-end workflow from Python to deployment on iOS and Android.

This is an early, experimental release that we will be building on in several areas over the coming months:

Provide APIs that cover common preprocessing and integration tasks needed for incorporating ML in mobile applications


## Firebase
**1. Firebase Realtime**

Store and sync data with our NoSQL cloud database. Data is synced across all clients in real time, and remains available when your app goes offline.
The Firebase Realtime Database is a cloud-hosted database. Data is stored as JSON and synchronized in real time to every connected client. When you build cross-platform apps with our iOS, Android, and JavaScript SDKs, all of your clients share one Realtime Database instance and automatically receive updates with the newest data.



**2.  Firebase Authentication**

Most apps need to know the identity of a user. Knowing a user's identity allows an app to securely save user data in the cloud and provide the same personalized experience across all of the user's devices.
Firebase Authentication provides backend services, easy-to-use SDKs, and ready-made UI libraries to authenticate users to your app. It supports authentication using passwords, phone numbers, popular federated identity providers like Google, Facebook and Twitter, and more.


**3. Cloud Storage**

Cloud Storage is built for app developers who need to store and serve user-generated content, such as photos or videos
Cloud Storage for Firebase is a powerful, simple, and cost-effective object storage service built for Google scale. The Firebase SDKs for Cloud Storage add Google security to file uploads and downloads for your Firebase apps, regardless of network quality. You can use our SDKs to store images, audio, video, or other user-generated content. On the server, you can use [Google Cloud Storage](https://cloud.google.com/storage), to access the same files.
