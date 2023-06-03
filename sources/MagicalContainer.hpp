#pragma once

#include <vector>

namespace ariel
{
	class MagicalContainer
	{
		private:
			std::vector<int> elements;

		public:
			MagicalContainer();

			void addElement(int element);

			void removeElement(int element);

			std::size_t size() const {
				return elements.size();
			}

			class AscendingIterator
			{
				private:
					MagicalContainer &container;
					std::size_t currentIndex;

					AscendingIterator(MagicalContainer &container, std::size_t index);

				public:
					AscendingIterator(MagicalContainer &cont);

					~AscendingIterator() = default;

					AscendingIterator(const AscendingIterator &other);

					AscendingIterator &operator=(const AscendingIterator &other);

					AscendingIterator(AscendingIterator &&other) noexcept;

					AscendingIterator &operator=(AscendingIterator &&other) noexcept;

					bool operator==(const AscendingIterator &other) const;

					bool operator!=(const AscendingIterator &other) const;

					bool operator<(const AscendingIterator &other) const;

					bool operator>(const AscendingIterator &other) const;

					int operator*() const;

					AscendingIterator &operator++();

					AscendingIterator begin() {
						return AscendingIterator(container, 0);
					}

					AscendingIterator end() const {
						return AscendingIterator(container, container.size());
					}
			};

			class SideCrossIterator
			{
				private:
					MagicalContainer &container;
					std::size_t currentIndex;

					SideCrossIterator(MagicalContainer &container, std::size_t index);

				public:
					SideCrossIterator(MagicalContainer &cont);

					~SideCrossIterator() = default;

					SideCrossIterator(const SideCrossIterator &other);

					SideCrossIterator &operator=(const SideCrossIterator &other);

					SideCrossIterator(SideCrossIterator &&other) noexcept;

					SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

					bool operator==(const SideCrossIterator &other) const;

					bool operator!=(const SideCrossIterator &other) const;

					bool operator<(const SideCrossIterator &other) const;

					bool operator>(const SideCrossIterator &other) const;

					int operator*() const;

					SideCrossIterator &operator++();

					SideCrossIterator begin() {
						return SideCrossIterator(container, 0);
					}

					SideCrossIterator end() const {
						return SideCrossIterator(container, container.size());
					}
			};

			class PrimeIterator
			{
				private:
					MagicalContainer &container;
					std::size_t currentIndex;

					PrimeIterator(MagicalContainer &container, std::size_t index);

				public:
					PrimeIterator(MagicalContainer &cont);

					~PrimeIterator() = default;

					PrimeIterator(const PrimeIterator &other);

					PrimeIterator &operator=(const PrimeIterator &other);

					PrimeIterator(PrimeIterator &&other) noexcept;

					PrimeIterator &operator=(PrimeIterator &&other) noexcept;

					bool operator==(const PrimeIterator &other) const;

					bool operator!=(const PrimeIterator &other) const;

					bool operator<(const PrimeIterator &other) const;

					bool operator>(const PrimeIterator &other) const;

					int operator*() const;

					PrimeIterator &operator++();

					PrimeIterator begin() {
						return PrimeIterator(container, 0);
					}

					PrimeIterator end() const {
						return PrimeIterator(container, container.size());
					}
			};
	};
}