# 2022 上半年存储状态报告

按照惯例，隔段时间我会写一次现在数据存储的基本状况。从本次起决定每半年报告一次数据存储状况。

## 存储设备

由于大学宿舍环境，目前存储方案全面转向 SSD 存储。

当前存储装置：

| Device Name           | Performance Level  | Disk Type  | Capacity | File System | Status   | Location | Notes                 | Healthy Status |
|-----------------------|--------------------|------------|----------|-------------|----------|----------|-----------------------|----------------|
| Western Digital HC330 | 4 (Cold Archive)   | HDD        | 10 TB    | ZFS         | Inactive | Home     | Important Archive     | OK             |
| Western Digital SN550 | 2 (OS & Cold Temp) | SSD (NVMe) | 1 TB     | NTFS        | Active   | Laptop   | Running Windows 11    | OK             |
| Samsung PM991A        | 3 (Hot Archive)    | SSD (NVMe) | 500 GB   | NTFS        | Active   | Laptop   | Extend Storage Laptop | OK             |
| Kioxia TC10           | 3 (Hot Archive)    | SSD (SATA) | 500 GB   | NTFS        | Active   | Disk Box | Not used now          | OK             |
| Kioxia RC20           | 1 (Hot Temp)       | SSD (NVMe) | 1 TB     | ZFS         | Ready    | Disk Box | Not setuped yet       | OK             |
| Kioxia RC20           | 1 (Hot Temp)       | SSD (NVMe) | 1 TB     | ZFS         | Ready    | Disk Box | Not setuped yet       | OK             |

总 HDD 存储：10 TB；活跃 0 TB。
总 SSD 存储：4 TB；活跃 4 TB。

其中在上次报告与本次报告间购置的设备：

* Koxia RC20 (1 TB) * 2

## 存储空间使用情况

| Device Name           | Disk Type  | Capacity | Used    |
|-----------------------|------------|----------|---------|
| Western Digital HC330 | HDD        | 10 TB    | ~500 GB |
| Western Digital SN550 | SSD (NVMe) | 1 TB     | ~300GB  |
| Samsung PM991A        | SSD (NVMe) | 500 GB   | ~300GB  |
| Kioxia TC10           | SSD (SATA) | 500 GB   | 0       |
| Kioxia RC20           | SSD (NVMe) | 1 TB     | 0       |
| Kioxia RC20           | SSD (NVMe) | 1 TB     | 0       |

## 备份情况

### 设备数据备份

| Device Name           | Disk Type  | Capacity | Backup Status               |
|-----------------------|------------|----------|-----------------------------|
| Western Digital HC330 | HDD        | 10 TB    | Almost fully backed up      |
| Western Digital SN550 | SSD (NVMe) | 1 TB     | No backup                   |
| Samsung PM991A        | SSD (NVMe) | 500 GB   | Important archive backed up |
| Kioxia TC10           | SSD (SATA) | 500 GB   | No data                     |
| Kioxia RC20           | SSD (NVMe) | 1 TB     | No data                     |
| Kioxia RC20           | SSD (NVMe) | 1 TB     | No data                     |

### 备份位置和检查

| Backup Infomation              | Location         | Size    | Backup Status         | Backup Last Check |
|--------------------------------|------------------|---------|-----------------------|-------------------|
| HC330 Important Archive Backup | OneDrive         | ~300 GB | !About +100 GB behind | !Not checked      |
| PM991A Music Backup (Local)    | Local Disk SN550 | ~25 GB  | Latest                | !Not checked      |
| PM991A Music Backup (Remote)   | OneDrive         | ~25GB   | Latest                | !Not checked      |

## 总结与展望

* 目前存储系统向 SSD 转移，但是 SSD 单机存储方案仍不成熟。需要使用 Linux + ZFS 确保完整性，但是比较麻烦。希望后续购买小型 NAS。
* 目前存储健康度良好，没有出现数据完整性问题或磁盘损毁问题，可喜可贺。
* 目前存储空间较为充足，得益于本次购置的两条 RC20 (1TB)，短期内存储需求应当得到满足。
* 目前存储性能充裕，有超过 1 TB 的较高性能固态硬盘，超过 2 TB 的中速固态和超过 5 TB 的企业级高性能机械硬盘。
* 未来希望更加充分的利用 ZFS 文件系统确保数据安全。
* 未来希望继续加强存储空间和性能，在资金允许情况下购置更大容量、更高性能的机械和固态硬盘，满足增长的存储需求。
* 未来希望加强存储空间利用率，比如想好方案在宿舍使用大容量机械硬盘。
* 未来需要加强备份的检测！没有检测的备份相当于没有备份！
