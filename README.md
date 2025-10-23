# 💡 Kontrol Lampu ESP32 dengan MIT App Inventor dan Node-RED

Proyek ini memungkinkan pengguna untuk **mengontrol lampu** menggunakan aplikasi Android (MIT App Inventor) yang berkomunikasi melalui **Node-RED** ke **ESP32**.  
Sistem ini dirancang untuk mengirimkan perintah **ON** dan **OFF** melalui jaringan WiFi lokal.

---

## 🧠 Arsitektur Sistem

MIT App Inventor → Node-RED (HTTP + WebSocket) → ESP32 → Relay / Lampu

- **MIT App Inventor (.aia)**: Membuat aplikasi Android yang mengirimkan perintah melalui HTTP.
- **Node-RED (.json)**: Menerima request dari App Inventor dan meneruskan perintah ke ESP32.
- **ESP32 (.ino)**: Mengontrol pin digital untuk menyalakan atau mematikan lampu.

---

## 📂 Struktur Proyek

| File | Deskripsi |
|------|------------|
| `LUK_LAMPU.aia` | Proyek MIT App Inventor (aplikasi Android) |
| `toggle.json` | Flow Node-RED untuk komunikasi data |
| `onoffMIT_.ino` | Kode program untuk ESP32 |
| `README.md` | Dokumentasi proyek |

---

## ⚙️ Instalasi dan Penggunaan

### 1️⃣ Upload Kode ke ESP32
1. Buka file `onoffMIT_.ino` di Arduino IDE.
2. Masukkan **SSID** dan **password WiFi** kamu.
3. Upload program ke board **ESP32**.
4. Catat **IP Address** ESP32 dari Serial Monitor.

### 2️⃣ Import Flow ke Node-RED
1. Buka Node-RED di browser (`http://localhost:1880`).
2. Klik **menu → Import → Upload file**, lalu pilih `toggle.json`.
3. Deploy flow tersebut.
4. Pastikan Node-RED berjalan dan terhubung ke ESP32.

### 3️⃣ Import Aplikasi ke MIT App Inventor
1. Masuk ke [MIT App Inventor](https://appinventor.mit.edu/).
2. Import file `LUK_LAMPU.aia`.
3. Ubah **alamat IP** sesuai dengan IP ESP32 kamu.
4. Build aplikasi dan install di HP Android.

---

## 🖼️ Tampilan Aplikasi

Aplikasi sederhana dengan dua tombol:
- **ON** untuk menyalakan lampu.
- **OFF** untuk mematikan lampu.
- Status akan muncul di debug Node-RED sebagai `on` atau `off`.

---

## 🧩 Flow Node-RED

Berikut node utama yang digunakan:

| Node | Fungsi |
|------|---------|
| `HTTP IN` | Menerima request dari MIT App |
| `JSON` | Parsing data JSON |
| `Function` | Mengambil nilai ON/OFF dan meneruskan ke ESP32 |
| `WebSocket` | Mengirim ke ESP32 |
| `Debug` | Menampilkan status di Node-RED |

---

## 📡 Komunikasi Data

- **HTTP POST (MIT → Node-RED)**  
  ```json
  { "ON": "" }
  ```
  atau  
  ```json
  { "OFF": "" }
  ```

- **WebSocket (Node-RED → ESP32)**  
  Mengirimkan payload sederhana:
  ```
  ON
  OFF
  ```

---

## 🧾 Lisensi

Proyek ini bersifat open source.  
Silakan modifikasi dan gunakan sesuai kebutuhan untuk pembelajaran atau pengembangan IoT pribadi.

---

## ✨ Kontributor
Dibuat oleh Lukman hafiz  — 2025 
Github : github.com/Lukmanhafiz
Email : harusdapetemas22@gmail.com
Terima kasih kepada komunitas Node-RED dan MIT App Inventor atas dokumentasi dan inspirasinya.
