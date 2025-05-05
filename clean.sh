#!/bin/bash

# ========================================
# 🧼 clean.sh - 실행파일 및 빌드 산출물 자동 삭제 스크립트
# 작성자: Umi
# 설명: C/C++ 프로젝트에서 컴파일 후 생성된 실행파일과 중간 파일(.o, .out 등)을 깔끔하게 삭제합니다.
# ========================================

# 📌 사용법
# ----------------------------------------
# 1. 이 파일을 프로젝트 루트 디렉토리에 저장하세요.
# 2. 최초 1회만 다음 명령어로 실행 권한을 부여하세요:
#    chmod +x clean.sh
# 3. 실행할 때는 이렇게 입력하세요:
#    ./clean.sh
# ----------------------------------------

echo ""
echo "🧹 [CLEANING] 전체 디렉토리에서 실행파일, .o, .out, .exe 정리 중..."
echo ""

# 1. 이름 기반으로 삭제
find . -type f \( -name "*.o" -o -name "*.out" -o -name "*.exe" -o -name "a.out" -o -name "hello" -o -name "run" -o -name "main" -o -name "test" \) -exec rm -f {} +

# 2. 실행 권한이 있고 확장자 없는 파일 삭제
find . -type f -executable ! -name "*.*" -exec rm -f {} +

# 3. build 디렉토리 내부 정리
if [ -d "build" ]; then
  rm -rf build/*
  echo "📂 build/ 디렉토리 정리 완료"
fi

echo ""
echo "✅ 전체 정리 완료!"
echo ""
