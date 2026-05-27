# 1. Indicamos la imagen base. Usamos Python oficial.
FROM python:3.10-slim

# 2. Establecemos la carpeta de trabajo dentro del contenedor
WORKDIR /app

# 3. Instalamos herramientas del sistema necesarias (opcional pero recomendado)
RUN apt-get update && apt-get install -y \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# 4. Copiamos el archivo de requisitos al contenedor
COPY requirements.txt .

# 5. Instalamos las librerías de Python (como PyTorch y Transformers)
RUN pip install --no-cache-dir -r requirements.txt

# 6. Copiamos el resto de nuestro código (el app.py) al contenedor
COPY . .

# 7. Exponemos el puerto donde correrá nuestra API
EXPOSE 8000

# 8. El comando que se ejecuta cuando el contenedor se enciende
CMD ["uvicorn", "app:app", "--host", "0.0.0.0", "--port", "8000"]