# Robot Deep Space 2019

## Installation de la librairie REV pour les Spark Max

- Se rendre sur http://www.revrobotics.com/sparkmax-software/ et télécharger la dernière version de l'API C++

- Suivre les instructions d'installation :

    Download and unzip the latest SPARK MAX C++ API into the `C:\Users\Public\frc2019\` directory.

    Follow the [Adding an offline-installed Library](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/682619-3rd-party-libraries#adding-an-offline-installed-library) instructions from WPI.


## Utilisation des librairies WPILib et REV

- Les classes WPILib sont dans `frc/` et celles REV dans `rev/`
    ```c++
    #include <frc/WPILib.h>
    #include <rev/SparkMax.h>
    ```

- Documentation en ligne [WPILib](http://first.wpi.edu/FRC/roborio/release/docs/cpp/index.html) et [REV](http://www.revrobotics.com/content/sw/max/sw-docs/cpp/index.html)