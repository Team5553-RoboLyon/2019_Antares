# Robot Deep Space 2019

## Installation de la librairie CTRE
Cross The Road Electonics pour les VictorSPX en CAN

- Se rendre sur https://github.com/CrossTheRoadElec/Phoenix-Releases/releases et télécharger la dernière version du zip appelé : `CTRE Phoenix Framework Installer x.xx.xx`

- Deziper le fichier et éxécuter l'installer

- Suivre les [Adding an offline-installed Library](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/682619-3rd-party-libraries#adding-an-offline-installed-library) instructions de WPI.


## Installation de la librairie REV pour les Spark Max

- Se rendre sur http://www.revrobotics.com/sparkmax-software/ et télécharger la dernière version de l'API C++

- Suivre les instructions d'installation :

    Download and unzip the latest SPARK MAX C++ API into the `C:\Users\Public\frc2019\` directory.

    Follow the [Adding an offline-installed Library](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/682619-3rd-party-libraries#adding-an-offline-installed-library) instructions from WPI.


## Utilisation des librairies WPILib et CTRE

- Les classes WPILib sont dans `frc/` et celles CTRE dans `ctre/`

- Pour inclure toutes les classes d'un coup :
    ```c++
    #include <frc/WPILib.h>
    #include <ctre/Phoenix.h>
    #include <rev/SparkMax.h>
    ```

- Documentation en ligne [WPILib](http://first.wpi.edu/FRC/roborio/release/docs/cpp/index.html), [CTRE](http://www.ctr-electronics.com/downloads/api/cpp/html/index.html) et [REV](http://www.revrobotics.com/content/sw/max/sw-docs/cpp/index.html)