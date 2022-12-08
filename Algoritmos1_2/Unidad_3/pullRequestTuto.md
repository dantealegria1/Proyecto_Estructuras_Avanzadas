# Como contribuir a un proyecto en github???

### 1. Tener una cuenta en github

### 2. Descargar e instalar git y gitbash en la computadora
#### - Link para la descarga: https://git-scm.com/ 
#### - Recomendación: descargar windows terminal desde microsoft store

### 3. Iniciar sesión en git bash
Abrir git bash y pegar los siguientes comandos:

```
$ git config --global user.name "John Doe"
$ git config --global user.email johndoe@example.com
```

### 4. Ir al link del repo y hacer un fork

### 5. Ir a nuestro perfil y dar en "code", y copiar el link que aparece

### 6. Ingresar a git bash e ingresar el comando
```
git clone <LINK_AQUI>
```

### 7. Ingresar al repo
```
cd <NOMBRE_DEL_REPO>
```

### 8. Crear una nueva rama local
```
git checkout -b <NOMBRE_DE_LA_RAMA>
```

### 9. Mover tus archivos al proyecto, puedes ingresar en la terminal
```
code .
```

### 10. Una vez en el editor, pegar tus archivos

### 11. Una vez realizados los cambios ir a la terminal y pegar
```
git add .
git commit -m '<COMENTARIO_EXPLICITO_DE_LOS_CAMBIOS_REALIZADOS>'
git push origin <NOMRE_DE_LA_RAMA>
```

### 12. Volver a nuestro perfil, en el repo, y dar click en "compare and pull request"

### 13. Ingresar un comentario explicito de los cambios y dar click en "create pull request"

Referencias
https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/working-with-your-remote-repository-on-github-or-github-enterprise/creating-an-issue-or-pull-request
https://www.digitalocean.com/community/tutorials/how-to-create-a-pull-request-on-github



