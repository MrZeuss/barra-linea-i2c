# Barra de línea analógica I²C de 8 canales

## Descripción
Ocho módulos IR individuales usando su salida AO, convertidos a I²C mediante dos ADS1015.

## Arquitectura / decisiones
ADS1015 #1 0x48: S1–S4. ADS1015 #2 0x49: S5–S8. Se usa AO; DO queda sin usar. Alimentación recomendada 3.3 V.

## Estructura
- `docs/`: descripción, mejoras y notas.
- `hardware/`: conexiones y notas de montaje.
- `images/`: diagramas generados durante el desarrollo.
- `code/`: firmware o plantillas disponibles.
- `bom/`: lista de materiales.

## Estado
Repositorio de documentación consolidado desde el hilo de diseño. Los esquemas gráficos son guías de montaje; antes de fabricar una PCB definitiva conviene verificar pinouts y datasheets de los módulos concretos.
