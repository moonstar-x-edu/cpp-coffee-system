# cpp-coffee-system

Proyecto de Programación 2 de la USFQ, un sistema de facturación de una cafetería.

Utiliza la libería [nlohmann/json](https://github.com/nlohmann/json) para el manejo de datos en formato JSON para mantener
persistencia de los datos de facturación.

Las clases que definen a los items de la cafetería, notablemente `Coffee`, `CoffeeBuilder` y `CoffeeDirector` implementan
(o al menos intentan implementar) un patrón de diseño llamado *Builder* para facilitar la construcción de objetos que tienen
tantas características distintas que su sus constructores podrían volverse un infierno. En escencia, la clase `Coffee`
corresponde a los objetos que representan el café, `CoffeeBuilder` la clase que sabe construir el café apropiado y el
`CoffeeDirector` el que sabe la receta de cada café. Idealmente, agregar más tipos de café debería convertirse en trabajo
fácil.
