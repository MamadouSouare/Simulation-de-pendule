🎯 **Simulation de Pendule en C (Raylib)**

Ce projet est une simulation simple du mouvement d’un pendule développée en C en utilisant la bibliothèque graphique Raylib.
L’objectif est de visualiser le comportement physique d’un pendule en fonction de sa longueur et de sa masse.

⚙️ **Fonctionnalités**
🎮 Simulation en temps réel du mouvement du pendule

⏸️ Possibilité de mettre en pause / reprendre la simulation

🖱️ Choix interactif de l’angle initial à la souris

📐 Paramètres configurables depuis la ligne de commande

| Action                  | Touche                   |
| ----------------------- | ------------------------ |
| Choisir l’angle initial | Clic gauche de la souris |
| Démarrer la simulation  | `Espace`                 |
| Pause / Reprendre       | `Espace`                 |


🛠️ **Compilation**
Assurez-vous d’avoir Raylib installé sur votre système.

Compilez avec la commande suivante :

```bash
gcc -o simul_pendule simul_pendule.c -lraylib -lm
```

ancez le programme avec :

```bash
./simul_pendule <len> <masse>
```

**Paramètres :**

-> **len** : longueur du fil du pendule (en pixels)

-> **masse** : masse du pendule

**Technologies utilisées**

**Langage** : C

**Bibliothèque graphique** : Raylib
