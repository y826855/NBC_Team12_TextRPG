# NBC_Team12_TextRPG
내일배움 캠프에서 진행하는 TEXT RPG 제작

## 🗺️ 노션
https://www.notion.so/teamsparta/12-3672dc3ef5148068a6c5c01bba994dcb?v=3672dc3ef514805ea946000c5316fdd5&source=copy_link

## 📝 기획 및 설계구조
https://miro.com/app/board/uXjVLi9zwcE=/

---
## 🎯 프로젝트 소개: "확장 가능한 객체지향 RPG 설계"
이 과제의 본질은 단순히 게임을 완성하는 것이 아니라, 객체지향 원칙(SOLID)을 적용해 나중에 몬스터나 아이템을 쉽게 추가할 수 있는 견고한 게임 시스템을 구축하는 것입니다.

📋 프로젝트 전체 구조도
🛠️ 세부 과제 리스트 (기능 요구사항)
모든 기능은 각 역할에 맞는 클래스로 모듈화하여 구현해야 합니다.

### 1. 캐릭터 및 성장 시스템
캐릭터 생성: 이름 설정 및 초기 스탯(레벨 1, 체력 200, 공격력 30, 경험치 0) 부여.

레벨업: 경험치 100 달성 시 레벨업. 레벨업 시마다 최대 체력(Lv x 20) 및 공격력(Lv x 5) 상승 후 체력 회복. (최대 레벨 10)

상태 확인: 게임 도중 언제든 캐릭터의 현재 상태를 출력.

### 2. 전투 및 보스 시스템
턴제 전투: 플레이어와 몬스터가 교대로 행동하는 자동 전투 로직.

보상 체계: 승리 시 경험치(50), 골드(10~20), 아이템(30% 확률) 획득.

보스전: 레벨 10 달성 시 등장. 일반 몬스터보다 1.5배 강력한 스탯을 가지며, 승리 시 게임 엔딩 도출.

### 3. 몬스터 스케일링
자동 스탯 부여: 플레이어 레벨에 비례하여 몬스터 능력치 자동 계산.

체력: (레벨 × 20) ~ (레벨 × 30)

공격력: (레벨 × 5) ~ (레벨 × 10)

### 4. 상점 및 인벤토리 시스템
경제 순환: 전투 보상으로 얻은 골드로 아이템 구매 및 판매(구매가의 60%로 환급).

아이템 효과:

포션: 즉시 체력 50 회복.

공격력 상승 아이템: 전투 중 공격력 보너스 부여.


## Class UML

클래스의 역활과 연결 구조를 나타내는 UML입니다
---
<img width="7126" height="6009" alt="EItem Ecosystem and Battle-2026-05-28-070251" src="https://github.com/user-attachments/assets/d6362d34-8ef0-4efb-b81b-2907595987d2" />

## Flow Chart
알고리즘의 조건 분기점을 나타내는 Flow Chart 입니다
---
<img width="3026" height="6327" alt="EItem Ecosystem and Battle-2026-05-28-061602" src="https://github.com/user-attachments/assets/1b9ec665-5652-4bee-b009-f3f5d34fb631" />


## Sequence Diagram
시간 흐름에 따라 구조들이 어떻게 호출되는 지 보여주는 Sequence Diagram 입니다
---
<img width="4119" height="8192" alt="Lobby Interaction Pipeline-2026-05-27-081627" src="https://github.com/user-attachments/assets/43572cfc-fa05-4369-a265-97853d17eb40" />

