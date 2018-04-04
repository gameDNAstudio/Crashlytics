# PLUGIN IS DEPRECATED

![Splash](Resources/Splash.png)

# Crashlytics

**Crashlytics** integrates out-of-the-box automatic crash reporting solution for **iOS & Android** into an Unreal Engine 4 project. Thanks to it you can spend less time on finding and more time on fixing crashes. Crashlytics provides deep and actionable insights, a real-time crash reporting solution, information about the number of crashes and affected users, the exact line of code game crashed on, and notifications about crashes via e-mail. Plugin includes all needed tools like symbols uploader and application configurator.

* **Current version:** 1.6.0
* **Binaries compiled for:** Unreal Engine 4.19
* **Required Unreal Engine 4.19 or above.**

## Features
* Real-time crash reporting tool
* Information about the number of crashes and affected users
* Provides the exact line of code your app crashed on
* Notifications about crashes via e-mail
* Works with dev & shipping builds
* Out-of-the-box for iOS & Android
* Additional SDK included
* Works with Blueprint-only & source code projects
* Works with Launcher & GitHub UE4 versions

## Blueprint nodes
![Splash](Resources/BlueprintSample.png)

## Setup
1. Copy this folder to the *Plugins* folder located in the main path of your project.

    ![CopyFiles](Resources/CopyFiles.png)

2. Enable *Crashlytics* in *Edit -> Plugins -> Misc -> Crashlytics*.

    ![EnablePlugin](Resources/EnablePlugin.png)

3. Go to _Edit -> Project Settings -> Crashlytics_ and set your _Crashlytics API Key_. You can obtain it on [fabric.io](http://www.fabric.io)
    
4. Turn on _Generate dSYM bundle for third party crash tools_ in _Project Settings_.

5. Go to _[PROJECT_FOLDER]/Build/Android/_

  a) If you already have created _custom_rules.xml_ file, simply add:
  ```xml
  <import file="crashlytics_build.xml" />
  ```
  b) If you don't have created _custom_rules.xml_ file yet, copy it from [[PLUGIN_FOLDER]/Extras/Android/custom_rules.xml](Extras/Android/custom_rules.xml).


Plugin icon designed by _Freepik_.
